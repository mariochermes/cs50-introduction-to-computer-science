/*markdown
Keep a log of any SQL queries you execute AS you solve the mystery.
Who the thief is,
What city the thief escaped to, and
Who the thief’s accomplice is who helped them escape
The theft took place on July 28, 2021 and that it took place on Humphrey Street.
*/

-- To see the database's structure.
.schema

-- Get information from crime scenes that match the place and date of the crime.
SELECT *
  FROM crime_scene_reports
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND street = 'Humphrey Street';

-- Check the interviews of the matching crime report.
SELECT *
  FROM interviews
 WHERE day = 28
   AND month = 7
   AND year = 2021

-- Obtain the license plates of those who left the bakery in the time range reported by Ruth.
SELECT *
  FROM bakery_security_logs
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND minute < 25
   AND activity = 'exit'

-- Get the info on the people who did atm transactions in the way Eugene described.
SELECT *
  FROM atm_transactions
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Check the id of the people who made the atm transactions.
SELECT *
  FROM atm_transactions AS at
       JOIN bank_accounts AS ba
       ON at.account_number = ba.account_number
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Retrieve the calls that possibly match the one that Raymond described. 
SELECT *
  FROM phone_calls
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND duration < 60

-- Find out the destination and the id of the first flight of 7/29/2021
SELECT *
  FROM airports
       JOIN flights
         ON flights.destination_airport_id = airports.id
 WHERE day = 29
   AND month = 7
   AND year = 2021
 ORDER BY hour
 LIMIT 1;

-- Get the passport numbers of the passengers in the first flight of day 29.
SELECT *
  FROM passengers
       JOIN flights
         ON passengers.flight_id = flights.id
 WHERE passengers.flight_id = 36;

-- Identify the thief by matching all the information.
SELECT people.*
  FROM people
       INNER JOIN bakery_security_logs AS bsl
       ON people.license_plate = bsl.license_plate
       INNER JOIN phone_calls AS pc
       ON people.phone_number = pc.caller
       INNER JOIN passengers
       ON people.passport_number = passengers.passport_number
       INNER JOIN
             (SELECT *
             FROM atm_transactions AS at
                  JOIN bank_accounts AS ba
                  ON at.account_number = ba.account_number)
             AS bt
       ON people.id = bt.person_id
   AND bsl.day = pc.day
   AND bsl.month = pc.month
   AND bsl.year = pc.year
 WHERE bsl.day = 28
   AND bsl.month = 7
   AND bsl.year = 2021
   AND bsl.hour = 10
   AND bsl.minute < 25
   AND bsl.activity = 'exit'
   AND pc.duration < 60
   AND passengers.flight_id = 36

-- Find out who is the accomplice by checking who the thief called while leaving the bakery
SELECT people.*
  FROM people
       JOIN phone_calls as pc
       ON people.phone_number = pc.receiver
 WHERE pc.day = 28
   AND pc.month = 7
   AND pc.year = 2021
   AND pc.duration < 60
   AND pc.caller = '(367) 555-5533'