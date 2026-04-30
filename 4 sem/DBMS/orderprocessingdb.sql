CREATE DATABASE ORDERPROCESSING520;
USE ORDERPROCESSING520;

CREATE TABLE CUSTOMER (
    custid INT,
    cname VARCHAR(30) NOT NULL,
    city VARCHAR(30),
    PRIMARY KEY (custid)
);

CREATE TABLE C_ORDER (
    orderid INT,
    odate DATE,
    custid INT,
    ordamt INT,
    PRIMARY KEY (orderid),
    FOREIGN KEY (custid) REFERENCES CUSTOMER (custid)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ITEM (
    itemid INT,
    price INT,
    PRIMARY KEY (itemid)
);

CREATE TABLE ORDER_ITEM (
    orderid INT,
    itemid INT,
    qty INT,
    PRIMARY KEY (orderid, itemid),
    FOREIGN KEY (orderid) REFERENCES C_ORDER (orderid)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (itemid) REFERENCES ITEM (itemid)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE WAREHOUSE (
    warehouseid INT,
    city VARCHAR(20) NOT NULL,
    PRIMARY KEY (warehouseid)
);

CREATE TABLE SHIPMENT (
    orderid INT,
    warehouseid INT,
    shipdt DATE,
    PRIMARY KEY (orderid, warehouseid),
    FOREIGN KEY (warehouseid) REFERENCES WAREHOUSE (warehouseid)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (orderid) REFERENCES C_ORDER (orderid)
        ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO CUSTOMER VALUES
(111, 'John Smith', 'Karkala'),
(112, 'Ramesh N', 'Nitte'),
(113, 'Franklin', 'Karkala'),
(114, 'Alica', 'Mangalore'),
(115, 'Raju', 'Udupi');

INSERT INTO C_ORDER VALUES
(201, '2001-08-03', 111, 3000),
(202, '2002-08-03', 111, 4000),
(203, '2001-08-04', 112, 8000),
(204, '2004-02-01', 113, 5000),
(205, '2001-04-02', 114, 2000);

INSERT INTO ITEM VALUES
(301, 2000),
(302, 2000),
(303, 1000),
(304, 5000),
(305, 4000);

INSERT INTO ORDER_ITEM VALUES
(201, 301, 2),
(201, 302, 4),
(201, 303, 4),
(202, 305, 4),
(203, 302, 1);

INSERT INTO WAREHOUSE VALUES
(1, 'Mangalore'),
(2, 'Mangalore'),
(3, 'Mangalore'),
(4, 'Udupi'),
(5, 'Udupi');

INSERT INTO SHIPMENT VALUES
(201, 1, '2001-04-02'),
(202, 2, '2002-05-12'),
(202, 4, '2003-06-01'),
(203, 2, '2004-02-01'),
(204, 4, '2004-06-02');

SELECT * FROM CUSTOMER;
SELECT * FROM C_ORDER;
SELECT * FROM ITEM;
SELECT * FROM ORDER_ITEM;
SELECT * FROM WAREHOUSE;
SELECT * FROM SHIPMENT;

-- Query 1: Customer name, number of orders, average order amount.
SELECT
    c.cname,
    COUNT(o.orderid) AS no_of_orders,
    AVG(o.ordamt) AS average_order_amount
FROM CUSTOMER c
JOIN C_ORDER o ON c.custid = o.custid
GROUP BY c.cname;

-- Query 2: Items with more than 2 orders shipped from at least 2 warehouses.
SELECT
    oi.itemid,
    COUNT(DISTINCT oi.orderid) AS no_of_orders,
    SUM(oi.qty) AS total_quantity
FROM ORDER_ITEM oi
WHERE oi.orderid IN (
    SELECT s.orderid
    FROM SHIPMENT s
    GROUP BY s.orderid
    HAVING COUNT(DISTINCT s.warehouseid) >= 2
)
GROUP BY oi.itemid
HAVING COUNT(DISTINCT oi.orderid) > 2;

-- Query 3: Customers who ordered every item produced by the company.
SELECT c.cname
FROM CUSTOMER c
WHERE NOT EXISTS (
    SELECT 1
    FROM ITEM i
    WHERE NOT EXISTS (
        SELECT 1
        FROM C_ORDER o
        JOIN ORDER_ITEM oi ON oi.orderid = o.orderid
        WHERE o.custid = c.custid
          AND oi.itemid = i.itemid
    )
);
