-- 코드를 입력하세요
SELECT b.TITLE, b.BOARD_ID, r.REPLY_ID,r.writer_id, r.CONTENTS, 
date_format(r.CREATED_DATE, '%Y-%m-%d')
FROM USED_GOODS_BOARD b JOIN USED_GOODS_REPLY r ON b.BOARD_ID = r.board_id
WHERE DATE_FORMAT(b.CREATED_DATE, '%Y-%m') = '2022-10'
order by r.created_date, b.title;