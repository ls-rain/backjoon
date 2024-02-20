-- 코드를 입력하세요
SELECT fh.flavor
from first_half fh join (Select flavor, sum(total_order) as total_order 
                         from july
                         group by flavor) j
on fh.flavor = j.flavor
order by (fh.total_order + j.total_order) desc
limit 3
