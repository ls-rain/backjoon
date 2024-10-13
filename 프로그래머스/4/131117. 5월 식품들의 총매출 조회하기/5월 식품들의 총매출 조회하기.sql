-- 코드를 입력하세요
SELECT fp.PRODUCT_ID, fp.PRODUCT_NAME, sum(fp.price * fo.amount) AS TOTAL_SALES
FROM FOOD_PRODUCT fp JOIN FOOD_ORDER fo ON fp.product_id = fo.product_id
WHERE fo.produce_date LIKE "2022-05%"
GROUP BY fp.product_id
ORDER BY total_sales desc, fp.product_id;
