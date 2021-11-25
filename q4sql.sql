CREATE TABLE BRANCH 
(
  CODE VARCHAR(2) PRIMARY KEY NOT NULL,
  NAME VARCHAR(25),
  ASSETS INT
);

CREATE TABLE CUSTOMER
(
  SSN INT NOT NULL PRIMARY KEY,
  NAME VARCHAR(25),
  PLACE VARCHAR(35)
);

CREATE TABLE TRANSACTION
(
  ACCNO INT REFERENCES ACCOUNT(ACCNO),
  CUSTOMERID INT REFERENCES CUSTOMER(SSN),
  CODE VARCHAR(2) REFERENCES BRANCH(CODE),
  TXN_TYPE VARCHAR(1),
  PRIMARY KEY(ACCNO,CUSTOMERID,CODE)
);

CREATE TABLE ACCOUNT 
(
  ACCNO VARCHAR(2),
  SSN INT REFERENCES CUSTOMER (SSN) ON DELETE CASCADE,
  CODE VARCHAR(2) REFERENCES BRANCH(CODE) ON DELETE CASCADE,
  BALANCE INT,
  PRIMARY KEY(ACCNO,SSN,CODE)
);

INSERT INTO BRANCH VALUES('b1','msr',10000);
INSERT INTO BRANCH VALUES('b2','rnr',20000);
INSERT INTO BRANCH VALUES('b3','smr',15000);
INSERT INTO BRANCH VALUES('b4','skr',25000);

INSERT INTO CUSTOMER VALUES(1,'ram','bng');
INSERT INTO CUSTOMER VALUES(2,'asha','mng');
INSERT INTO CUSTOMER VALUES(3,'usha','mys');
INSERT INTO CUSTOMER VALUES(4,'sri','del');

INSERT INTO ACCOUNT VALUES('a1',1,'b1',100000);
INSERT INTO ACCOUNT VALUES('a2',1,'b1',200000);
INSERT INTO ACCOUNT VALUES('a3',2,'b2',100000);
INSERT INTO ACCOUNT VALUES('a4',3,'b2',100000);
INSERT INTO ACCOUNT VALUES('a5',3,'b2',100000);
INSERT INTO ACCOUNT VALUES('a6',3,'b2',100000);
INSERT INTO ACCOUNT VALUES('a7',4,'b2',200000);

select * from ACCOUNT;

select * from CUSTOMER;

select * from BRANCH;

