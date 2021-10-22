-- SET N = N - 1
select salary from Employee
order by salary ASC
limit 1 offset N;