# Write your MySQL query statement below
select empu.unique_id , e1.name from employees e1
left join EmployeeUNI empu on empu.id = e1.id;