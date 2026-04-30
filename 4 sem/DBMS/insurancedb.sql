IF DB_ID('INSURANCE201') IS NOT NULL
    DROP DATABASE INSURANCE201;
GO
CREATE DATABASE INSURANCE201;
GO
USE INSURANCE201;
GO

CREATE TABLE PERSON(
    driver_id VARCHAR(20),
    name CHAR(20),
    address VARCHAR(30),
    PRIMARY KEY(driver_id)
);

CREATE TABLE CAR(
    regno VARCHAR(20),
    model VARCHAR(20),
    year INT,
    PRIMARY KEY(regno)
);

CREATE TABLE ACCIDENT(
    reportno VARCHAR(20),
    accd_date DATE,
    location VARCHAR(30),
    PRIMARY KEY(reportno)
);

CREATE TABLE OWNS(
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    PRIMARY KEY(driver_id, regno),
    FOREIGN KEY(driver_id) REFERENCES PERSON(driver_id)
      ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(regno) REFERENCES CAR(regno)
      ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE PARTICIPATED(
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    report_no VARCHAR(20),
    dmg_amt INT,
    PRIMARY KEY(driver_id, regno, report_no),
    FOREIGN KEY(driver_id) REFERENCES PERSON(driver_id)
      ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(regno) REFERENCES CAR(regno)
      ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(report_no) REFERENCES ACCIDENT(reportno)
      ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO PERSON VALUES
('1a','John Smith','Nitte'),
('2b','David Smith','Karkala'),
('3c','Michael Smith','Manipal'),
('4d','Diana Smith','Udupi'),
('5e','Smith','Mangalore');

INSERT INTO CAR VALUES
('KA12','Hyundai',2024),
('KA13','Suzuki',2021),
('KA14','Toyota',2022),
('KA15','BMW',2023),
('KA11','Benz',2007);

INSERT INTO ACCIDENT VALUES
('1A','2025-01-06','Mangalore'),
('2B','2023-02-21','Bangalore'),
('3C','1989-03-16','Udupi'),
('4D','1999-04-07','Manipal'),
('5E','2006-05-21','Nitte');

INSERT INTO OWNS VALUES
('1a','KA12'),
('2b','KA13'),
('3c','KA14'),
('4d','KA15');

INSERT INTO PARTICIPATED VALUES
('1a','KA12','1A',1000),
('2b','KA13','2B',2000),
('3c','KA14','3C',2500),
('4d','KA15','4D',2400),
('5e','KA11','5E',4695);

SELECT * FROM PERSON;
SELECT * FROM CAR;
SELECT * FROM ACCIDENT;
SELECT * FROM OWNS;
SELECT * FROM PARTICIPATED;

-- 1) Total number of people who owned cars involved in accidents in 1989.
SELECT COUNT(DISTINCT P.driver_id) AS total_no_count
FROM ACCIDENT A, PARTICIPATED P
WHERE A.reportno = P.report_no
  AND YEAR(A.accd_date) = 1989;

-- 2) Number of accidents in which cars of John Smith were involved.
SELECT COUNT(P.report_no) AS No_of_acc
FROM PARTICIPATED P, PERSON PN
WHERE P.driver_id = PN.driver_id
  AND PN.name = 'John Smith';

-- 3) Update damage amount.
UPDATE PARTICIPATED
SET dmg_amt = 3000
WHERE report_no = '1A' AND regno = 'KA12';

SELECT * FROM PARTICIPATED;
