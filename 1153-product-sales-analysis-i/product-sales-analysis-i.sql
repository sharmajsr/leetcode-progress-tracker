# Write your MySQL query statement below
select p1.product_name , s1.year, s1.price from sales s1
left join product p1 on p1.product_id = s1.product_id ;