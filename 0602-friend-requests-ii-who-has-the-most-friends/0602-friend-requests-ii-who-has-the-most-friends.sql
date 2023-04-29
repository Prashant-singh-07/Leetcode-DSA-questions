# Write your MySQL query statement below

select requester_id as id,(select count(t.requester_id) from RequestAccepted as t where t.requester_id = id OR t.accepter_id=id) as num from RequestAccepted group by id order by num desc limit 1;