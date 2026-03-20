create database studentdb;
use studentdb;

create table student(
    regno varchar(10),
    sname varchar(30) not null,
    major varchar(20),
    bdate date,
    primary key(regno)
);

create table course(
    course_no int,
    cname varchar(30) not null,
    dept varchar(20),
    primary key(course_no)
);

create table enroll(
    regno varchar(10),
    course_no int,
    sem int,
    marks int,
    primary key(regno, course_no),
    foreign key(regno) references student(regno) on delete cascade on update cascade,
    foreign key(course_no) references course(course_no) on delete cascade on update cascade
);

create table textbook(
    book_isbn int,
    book_title varchar(60),
    publisher varchar(30),
    author varchar(30),
    primary key(book_isbn)
);

create table bookadoption(
    course_no int,
    sem int,
    book_isbn int,
    primary key(course_no, sem, book_isbn),
    foreign key(course_no) references course(course_no) on delete cascade on update cascade,
    foreign key(book_isbn) references textbook(book_isbn) on delete cascade on update cascade
);

insert into student values('NNM01','Smith','Education','1992-01-02');
insert into student values('NNM02','Bob','Exam','1999-03-10');
insert into student values('NNM03','Alice','Academics','1991-05-29');
insert into student values('NNM04','John','Research','1992-08-10');
insert into student values('NNM05','Tom','Accounts','1986-07-20');

insert into course values(1,'DBMS','CSE');
insert into course values(2,'ESC','ISE');
insert into course values(3,'IDT','ME');
insert into course values(4,'MP','CSE');
insert into course values(5,'BEE','ECE');

insert into textbook values(1,'Machine','Pearson','Alfred');
insert into textbook values(2,'Thermodynamic','Penguin','Rajkomal');
insert into textbook values(3,'Circuit Theory','McGraw','Ragavan');
insert into textbook values(4,'Fundamentals','SBC','Nithin');
insert into textbook values(5,'Electronics','McGraw','Balaguru');

insert into bookadoption values(1,3,2);
insert into bookadoption values(1,4,4);
insert into bookadoption values(2,6,1);
insert into bookadoption values(3,1,5);
insert into bookadoption values(3,2,3);

insert into enroll values('NNM01',1,4,92);
insert into enroll values('NNM02',2,4,89);
insert into enroll values('NNM03',3,3,70);
insert into enroll values('NNM04',4,6,67);
insert into enroll values('NNM05',5,6,100);

select * from student;
select * from course;
select * from textbook;
select * from bookadoption;
select * from enroll;

-- 1) Textbook details for CSE courses that use more than two books.
select t.book_isbn, t.book_title, c.course_no, c.cname
from textbook t, course c, bookadoption b
where t.book_isbn = b.book_isbn
  and c.course_no = b.course_no
  and c.dept = 'CSE'
  and c.course_no in (
      select course_no
      from bookadoption
      group by course_no
      having count(*) > 2
  )
order by t.book_title;

-- 2) Department(s) where all adopted books are from publisher MCGRAW.
select distinct(c.dept)
from course c
where not exists (
    select b.book_isbn
    from bookadoption b
    where b.course_no in (
        select c2.course_no
        from course c2
        where c2.dept = c.dept
    )
    and b.book_isbn not in (
        select t.book_isbn
        from textbook t
        where t.publisher = 'MCGRAW'
    )
);

-- 3) Book ISBN and title for the department with maximum students.
select t.book_isbn, t.book_title
from textbook t, course c, bookadoption b
where b.course_no = c.course_no
  and t.book_isbn = b.book_isbn
  and c.dept in (
      select c2.dept
      from course c2, enroll e
      where c2.course_no = e.course_no
      group by c2.dept
      having count(distinct e.regno) >= all (
          select count(distinct e2.regno)
          from course c3, enroll e2
          where c3.course_no = e2.course_no
          group by c3.dept
      )
  );
