-- 코드를 입력하세요
SELECT category, sum(sales) as total_sales
FROM book b JOIN book_sales s ON b.book_id = s.book_id
WHERE sales_date LIKE "2022-01%"
GROUP BY category
ORDER BY category;