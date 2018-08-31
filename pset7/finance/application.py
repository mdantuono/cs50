import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")



@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    totalPrice=0
    portfolio = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])
    user = db.execute("SELECT * FROM users WHERE id=:id", id=session["user_id"])
    for row in portfolio:
        # print(row)
        updatedInfo = lookup(row["symbol"])
        db.execute("UPDATE portfolio SET 'price' = :u WHERE symbol = :s", u=updatedInfo['price'], s=row["symbol"])
    portfolio = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])
    for row in portfolio:
        totalPrice += row["price"] * row["shares"]
    # print(user[0])
    return render_template("index.html", portfolio=portfolio, usd=usd, user=user[0], totalPrice=totalPrice)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))
        # print(stock["symbol"])
        shares = int(request.form.get("shares"))
        # print(shares)
        portfolio = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])
        print(portfolio)
        user = db.execute("SELECT * FROM users WHERE id=:id", id=session["user_id"])
        for i in portfolio:
            print(i)
            if i["symbol"] == stock["symbol"]:
                db.execute("UPDATE portfolio SET 'shares' = shares + :sh WHERE symbol=:s", sh=shares, s=stock["symbol"])
                db.execute("UPDATE users SET 'cash' = cash - :c WHERE id=:id", c=shares * stock["price"], id=session["user_id"])
                return redirect("/")

        db.execute("INSERT INTO portfolio (symbol,price,shares,id) VALUES (:s,:p,:sh,:id)", s=stock["symbol"], p=stock["price"], sh=shares, id=session["user_id"])
        db.execute("UPDATE users SET 'cash' = cash - :c where id=:id", c=shares * stock["price"], id=session["user_id"])
        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT * from portfolio where id=:id", id=session["user_id"])
    for row in transactions:
        print(row)
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))
        print(rows)
        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        userName = (rows[0]["username"])
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))
        print(stock)
        return render_template("quote.html", stock=stock)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        db.execute("INSERT INTO users (username, hash) VALUES (:u, :p)", u=request.form.get("username"), p=generate_password_hash(request.form.get("password")))
        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        portfolio = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])
        print(portfolio)
        for stock in portfolio:
            print(stock)
            if stock["symbol"] == symbol:
                if stock["shares"] > 1 and stock["shares"] > shares:
                    db.execute("UPDATE portfolio SET 'shares'=shares-:sh where symbol=:s", sh=shares, s=symbol)
                elif stock["shares"] == 1:
                    db.execute("DELETE FROM portfolio WHERE symbol=:s", s=symbol)

        return redirect("/")
    else:
        return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
