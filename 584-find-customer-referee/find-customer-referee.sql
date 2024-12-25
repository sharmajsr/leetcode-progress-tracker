# Write your MySQL query statement below
select name from ( select name, coalesce(referee_id,1) as ref_id from customer  ) as wp  where ref_id != 2 ;