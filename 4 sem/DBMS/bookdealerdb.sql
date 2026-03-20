CREATE DATABASE BOOKDEALER;
USE BOOKDEALER;

CREATE TABLE AUTHOR(
    author_id INT,
    aname CHAR(20),
    acity CHAR(20),
    acountry CHAR(20),
    PRIMARY KEY(author_id)
);

CREATE TABLE PUBLISHER(
    publisher_id INT,
    pname CHAR(20),
    pcity CHAR(20),
    pcountry CHAR(20),
    PRIMARY KEY(publisher_id)
);

CREATE TABLE CATEGORY(
    category_id INT,
    description CHAR(30),
    PRIMARY KEY(category_id)
);

CREATE TABLE CATALOG(
    bookid INT,
    title VARCHAR(20),
    author_id INT,
    publisher_id INT,
    category_id INT,
    year INT,
    price INT,
    PRIMARY KEY(bookid),
    FOREIGN KEY(author_id) REFERENCES AUTHOR(author_id)
      ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(publisher_id) REFERENCES PUBLISHER(publisher_id)
      ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(category_id) REFERENCES CATEGORY(category_id)
      ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ORDER_DETAILS(
    order_no INT,
    book_id INT,
    quantity INT,
    PRIMARY KEY(order_no, book_id),
    FOREIGN KEY(book_id) REFERENCES CATALOG(bookid)
      ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO AUTHOR VALUES
(100,'Ruskin Bond','Texas','London'),
(101,'Dale','Nitte','India'),
(102,'Sudha','Bangalore','India'),
(103,'Shiva','Mysore','India'),
(104,'Chetan Bhagat','Delhi','India'),
(105,'Navathe','Hang Kong','Japan'),
(106,'Jane','Florida','Australia'),
(107,'Robin','Amster','Afghan');

INSERT INTO PUBLISHER VALUES
(200,'Penguin','Paris','France'),
(201,'Sapna','Mumbai','India'),
(202,'Rupa','Delhi','India'),
(203,'Savi','Madrid','France'),
(204,'Pearson','Barcelona','Japan'),
(205,'Ramesh','Paris','France'),
(206,'Little House','Texas','London'),
(207,'Delin','Karnataka','India');

INSERT INTO CATEGORY VALUES
(300,'Selfhelp'),
(301,'Fiction'),
(302,'Fiction'),
(303,'Non-fiction'),
(304,'Spiritual'),
(305,'Self help');

INSERT INTO CATALOG VALUES
(4001,'The Blue',100,200,300,2019,350),
(4002,'Life Lesson',101,201,301,2020,299),
(4003,'Mystery',102,202,302,2021,450),
(4004,'Technology',103,203,303,2018,250),
(4005,'Mind Power',104,204,304,2022,605.6),
(4006,'Business',105,205,305,2017,300),
(4007,'Science Facts',106,206,306,2016,200),
(4008,'Self growth',107,207,307,2023,600);

INSERT INTO ORDER_DETAILS VALUES
(01,4003,1),
(02,4002,3),
(03,4005,7),
(04,4004,1),
(05,4006,1),
(06,4007,4),
(07,4008,2),
(08,4001,2);

SELECT * FROM AUTHOR;
SELECT * FROM PUBLISHER;
SELECT * FROM CATEGORY;
SELECT * FROM CATALOG;
SELECT * FROM ORDER_DETAILS;

1) SELECT A.author_id, A.aname, A.acity, SUM(O.quantity) AS QTY_SUM
   FROM AUTHOR A, CATALOG C, ORDER_DETAILS O
   WHERE A.author_id = C.author_id
     AND C.bookid = O.book_id
   GROUP BY A.author_id, A.aname, A.acity, C.bookid
   HAVING SUM(quantity) >= ALL (
       SELECT SUM(quantity) FROM ORDER_DETAILS GROUP BY book_id
   );

2) UPDATE CATALOG SET price = price * 1.1
   WHERE publisher_id IN (
       SELECT publisher_id FROM publisher
       WHERE pname = 'Pearson'
   );

3) SELECT COUNT(order_no) AS 'NO_OF_ORDERS', book_id
   FROM ORDER_DETAILS
   GROUP BY book_id
   HAVING SUM(quantity) <= ALL (
       SELECT SUM(quantity) FROM ORDER_DETAILS GROUP BY book_id
   );
