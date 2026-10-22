-- Experiment 3: JSP + JDBC CRUD on the students table
CREATE DATABASE IF NOT EXISTS studentDB;
USE studentDB;

CREATE TABLE IF NOT EXISTS students (
    roll_no INT PRIMARY KEY,
    name    VARCHAR(50),
    email   VARCHAR(100),
    age     INT
);

DESC students;

-- Optional test rows (you can also add them from addStudent.jsp)
-- INSERT INTO students (roll_no, name, email, age) VALUES
-- (101, 'Rahul', 'rahul@gmail.com', 20),
-- (102, 'Priya', 'priya@gmail.com', 19);
