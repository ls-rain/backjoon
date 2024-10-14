-- 코드를 입력하세요
SELECT year(sales_date) as year, month(sales_date) as month, count(distinct u.user_id) as purchased_users,
round(count(distinct u.user_id) / (select count(*) FROM user_info WHERE year(joined) = 2021), 1) as PUCHASED_RATIO
FROM user_info u JOIN online_sale o ON u.user_id = o.user_id
WHERE u.joined LIKE "2021%"
GROUP BY year(sales_date), month(sales_date)
ORDER BY year, month;