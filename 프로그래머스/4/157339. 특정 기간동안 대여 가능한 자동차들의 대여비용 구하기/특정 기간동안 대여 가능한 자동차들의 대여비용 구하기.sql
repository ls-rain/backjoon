-- 코드를 입력하세요
SELECT r.CAR_ID, r.CAR_TYPE, ROUND(r.daily_fee*30*(100-d.discount_rate)/100) as FEE
FROM CAR_RENTAL_COMPANY_CAR r 
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY h ON r.car_id = h.car_id 
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN d ON r.car_type = d.car_type
WHERE r.car_id not in (SELECT car_id
                      FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                      WHERE start_date < "2022-12-01" and end_date > "2022-11-01")
                      AND d.DURATION_TYPE = "30일 이상"
GROUP BY r.car_id
HAVING r.car_type in ("세단", "SUV") and (FEE >=500000 AND FEE < 2000000)
ORDER BY FEE desc, car_type, car_id desc;