<?php
	$Con=new mysqli("localhost", "root", "", "db_project");
	$Name=filter_input(0,"Stuname");
	$RNo=filter_input(0,"StuRollnumber");	
	$Cat=filter_input(0,"StuCat");
	$Exp=filter_input(0,"StuExperience");
	$EmailId=filter_input(0,"StuEmail");
	$Password=filter_input(0,"StuPassword");
	$SCat1=filter_input(0,'StuSCat1');
	$SCat2=filter_input(0,'StuSCat2');
	echo $Name;
	echo $RNo;
	echo $Cat;
	echo $Exp;
	echo $EmailId;
	echo $Password;
	echo $SCat1;
	echo $SCat2;
	if($SCat1=='SCat1')
		$SCat1=null;
	if($SCat2=='SCat2')
		$SCat2=null;
	$Query="insert into logininfo(UserName, RollNo, Category, SCat1, SCat2, Exp, Email, Password) values ('$Name', '$RNo', '$Cat', '$SCat1', '$SCat2', '$Exp', '$EmailId', '$Password')";
	$Con->Query($Query);
?>