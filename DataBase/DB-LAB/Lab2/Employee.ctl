LOAD DATA
INFILE Employee.csv
Append into table Employee1
Fields terminated by ',' optionally enclosed by '"'
Trailing NULLCols
(Fname,Minit,Lname,Ssn,Bdate DATE 'yyyy-mm-dd', Address,Sex,Salary,Super_ssn,Dno)
