# Write your MySQL query statement below
select empu.unique_id as unique_id , name from employees emp
left join EmployeeUNI empu on empu.id = emp.id;