-- Keep a log of any SQL queries you execute as you solve the mystery.
//Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
//Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

//within ten minutes of the theft in backery parking lot
//earlier this morning, thief withdraw money
//thief leaving bakery, call someone less than minute, take the earliest flight tomorrow, ask someone to purchase the ticket
SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year=2021;

SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute>15 AND minute<25 AND activity = 'exit';

SELECT id, account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';

SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street');

SELECT caller, receiver FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;

//sofia diana kelsey bruce 在麵包店出入 和 電話紀錄
SELECT name, license_plate, phone_number, passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute>15 AND minute<25 AND activity = 'exit') AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60);

//id=8
SELECT id, abbreviation, full_name, city FROM airports;
//最早id=36
SELECT id, hour, minute FROM flights WHERE month = 7 AND day = 29 AND year = 2021 AND origin_airport_id = 8;

SELECT passport_number FROM passengers WHERE flight_id = 36;

//sofia kelsy bruce
SELECT id, name, license_plate, phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute>15 AND minute<25 AND activity = 'exit') AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60) AND passport_number IN(SELECT passport_number FROM passengers WHERE flight_id = 36) AND id IN(SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'));

SELECT destination_airport_id FROM flights WHERE id=36;

SELECT name FROM people WHERE phone_number = '(375) 555-8161';
