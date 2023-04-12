-- Keep a log of any SQL queries you execute as you solve the mystery.

-- We know that the theft took plane on 7/28/2021, and that it took place on Humphrey Street.
SELECT *
FROM crime_scene_reports
WHERE street = "Humphrey Street"
AND month = 7
AND day = 28
AND year = 2021;

--
-- | 295 | 2021 | 7     | 28  | Humphrey Street |
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

-- since the interview transcript mentions bakery
SELECT * FROM interviews WHERE transcript LIKE "%bakery%" ;
-- notable interviews include:
-- 161: Ruth: Thief got into a car sometime within ten minutes of the theft.
-- 162: Eugene: Recognized the thief. Widthrawing some money on Leggett Street ATM
-- 163: Raymond: earliest flight out of Fiftyville tomorrow. Less than 1 minute call.

-- around nine transactions
SELECT * FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28 AND year = 2021;

-- results too long at the moment to eliminate
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 and duration < 60;

-- earliest flight tomorrow is flight id 36
SELECT * FROM flights WHERE month = 7 AND day = 29 AND year = 2021 ORDER BY hour;
--+----+-------------------+------------------------+------+-------+-----+------+--------+
--| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
--+----+-------------------+------------------------+------+-------+-----+------+--------+
--| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |

-- to deduce where the city the thief escaped to. this hint was brought by the destination_airport_id
-- ans: New York City
SELECT * FROM airports WHERE id = 4;
--+----+--------------+-------------------+---------------+
--| id | abbreviation |     full_name     |     city      |
--+----+--------------+-------------------+---------------+
--| 4  | LGA          | LaGuardia Airport | New York City |
--+----+--------------+-------------------+---------------+

-- attempt to extract license plates of those who exited within 10 minutes of the theft
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND activity = "exit" AND minute <= 25;

-- this one was my favorite query line, it wasn't written all at once, but built slowly
-- I had to keep using .schema to find the common columns in order to connect the tables
-- and narrow the rows down.
-- the WHERE values are also based on the specs
SELECT DISTINCT name,
phone_number,
phone_calls.receiver,
people.passport_number,
people.license_plate,
people.id,
phone_calls.duration,
bank_accounts.account_number,
flights.id
FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE activity = "exit"
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.year = 2021
AND bakery_security_logs.hour = 10
AND phone_calls.day = 28
AND phone_calls.duration < 60
AND flights.id = 36
AND destination_airport_id = 4
AND bakery_security_logs.minute <= 25;

-- one liner version is:
-- SELECT DISTINCT(name),phone_number,phone_calls.receiver,people.passport_number,people.license_plate,people.id,phone_calls.duration,bank_accounts.account_number,flights.id FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate JOIN phone_calls ON phone_calls.caller = people.phone_number JOIN bank_accounts ON bank_accounts.person_id = people.id JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number JOIN passengers ON passengers.passport_number = people.passport_number JOIN flights ON flights.id = passengers.flight_id WHERE activity = "exit" AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.year = 2021 AND bakery_security_logs.hour = 10 AND phone_calls.duration < 60 AND flights.id = 36 AND destination_airport_id = 4 AND bakery_security_logs.minute <= 25 AND phone_calls.day = 28;

-- sanity checking bruce's license plate lmao
SELECT license_plate FROM people WHERE name = "Bruce";

-- since we know that the thief is Bruce, we can deduce his accomplice by
-- looking for the name of the receiver of the call.
SELECT name FROM people WHERE phone_number = "(375) 555-8161";