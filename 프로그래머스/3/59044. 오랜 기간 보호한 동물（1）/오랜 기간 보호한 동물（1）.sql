-- 코드를 입력하세요
SELECT i.NAME, i.DATETIME
FROM ANIMAL_INS i
left JOIN ANIMAL_OUTS o ON i.animal_id = o.animal_id
WHERE o.animal_id is null
ORDER BY i.datetime limit 3;