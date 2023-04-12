import cs50


def get_cents():
    while True:
        get_cents = cs50.get_float("Change owed: ")
        if (0 < get_cents):
            break
    return get_cents * 100


def calculate_quarters(cents):
    print("current cents: ", cents)  # print statements for sanity check
    quarters = cents // 25
    print("Quarters: ", quarters)
    return quarters


def calculate_dimes(cents):
    print("current cents: ", cents)  # print statements for sanity check
    dimes = cents // 10
    print("Dimes: ", dimes)
    return dimes


def calculate_nickels(cents):
    print("current cents: ", cents)  # print statements for sanity check
    nickels = cents // 5
    print("Nickels: ", nickels)
    return nickels


def calculate_pennies(cents):
    print("current cents: ", cents)  # print statements for sanity check
    pennies = cents // 1
    print("Pennies: ", pennies)
    return pennies


cents = get_cents()

quarters = calculate_quarters(cents)  # calculates number of quarters to give the customer
cents = cents - quarters * 25

dimes = calculate_dimes(cents)  # calculates number of dimes to give the customer
cents = cents - dimes * 10

nickels = calculate_nickels(cents)  # calculates number of nickels to give the customer
cents = cents - nickels * 5

pennies = calculate_pennies(cents)  # calculates the number of pennies to give the customer
cents = cents - pennies * 1

coins = int(quarters + dimes + nickels + pennies)  # obtain total number of coins

print(coins)  # print result or answer