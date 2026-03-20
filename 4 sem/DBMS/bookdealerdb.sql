create database bookdealerdb;
use bookdealerdb;

create table author(
    author_id int,
    aname varchar(30),
    acity varchar(20),
    acountry varchar(20),
    primary key(author_id)
);

create table publisher(
    publisher_id int,
    pname varchar(30),
    pcity varchar(20),
    pcountry varchar(20),
    primary key(publisher_id)
);

create table category(
    category_id int,
    description varchar(30),
    primary key(category_id)
);

create table catalog(
    book_id int,
    title varchar(40),
    author_id int,
    publisher_id int,
    category_id int,
    pyear int,
    price decimal(10,2),
    primary key(book_id),
    foreign key(author_id) references author(author_id) on delete cascade on update cascade,
    foreign key(publisher_id) references publisher(publisher_id) on delete cascade on update cascade,
    foreign key(category_id) references category(category_id) on delete cascade on update cascade
);

create table order_details(
    order_no int,
    book_id int,
    quantity int,
    primary key(order_no, book_id),
    foreign key(book_id) references catalog(book_id) on delete cascade on update cascade
);

insert into author values(100,'Ruskin Bond','Texas','London');
insert into author values(101,'Dale','Nitte','India');
insert into author values(102,'Sudha','Bangalore','India');
insert into author values(103,'Shiva','Mysore','India');
insert into author values(104,'Chetan Bhagat','Delhi','India');
insert into author values(105,'Navathe','Hong Kong','Japan');
insert into author values(106,'Jane','Florida','Australia');
insert into author values(107,'Robin','Amster','Afghan');

insert into publisher values(200,'Penguin','Paris','France');
insert into publisher values(201,'Sapna','Mumbai','India');
insert into publisher values(202,'Rupa','Delhi','India');
insert into publisher values(203,'Savi','Madrid','France');
insert into publisher values(204,'Pearson','Barcelona','Japan');
insert into publisher values(205,'Ramesh','Paris','France');
insert into publisher values(206,'Little House','Texas','London');
insert into publisher values(207,'Delin','Karnataka','India');

insert into category values(300,'Selfhelp');
insert into category values(301,'Fiction');
insert into category values(302,'Fiction');
insert into category values(303,'Non-fiction');
insert into category values(304,'Spiritual');
insert into category values(305,'Self help');

insert into catalog values(4001,'The Blue',100,200,300,2019,350.00);
insert into catalog values(4002,'Life Lesson',101,201,301,2020,299.00);
insert into catalog values(4003,'Mystery',102,202,302,2021,450.00);
insert into catalog values(4004,'Technology',103,203,303,2018,250.00);
insert into catalog values(4005,'Mind Power',104,204,304,2022,605.60);
insert into catalog values(4006,'Business',105,205,305,2017,300.00);
insert into catalog values(4007,'Science Facts',106,206,306,2016,200.00);
insert into catalog values(4008,'Self Growth',107,207,307,2023,600.00);

insert into order_details values(1,4003,1);
insert into order_details values(2,4002,3);
insert into order_details values(3,4005,7);
insert into order_details values(4,4004,1);
insert into order_details values(5,4006,1);
insert into order_details values(6,4007,4);
insert into order_details values(7,4008,2);
insert into order_details values(8,4001,2);

select * from author;
select * from publisher;
select * from category;
select * from catalog;
select * from order_details;

-- 1) Author details of books having maximum sales.
select a.author_id, a.aname, a.acity, sum(o.quantity) as qty_sum
from author a, catalog c, order_details o
where a.author_id = c.author_id
  and c.book_id = o.book_id
group by a.author_id, a.aname, a.acity, c.book_id
having sum(o.quantity) >= all (
    select sum(quantity)
    from order_details
    group by book_id
);

-- 2) Increase price of books from publisher PEARSON by 10%.
update catalog
set price = price * 1.1
where publisher_id in (
    select publisher_id
    from publisher
    where pname = 'Pearson'
);

select * from catalog;

-- 3) Number of orders for books with minimum sales.
select count(order_no) as NO_OF_ORDERS, book_id
from order_details
group by book_id
having sum(quantity) <= all (
    select sum(quantity)
    from order_details
    group by book_id
);
