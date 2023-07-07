-- 코드를 입력하세요
SELECT b.title, b.board_id, r.reply_id, r.writer_id, r.contents,DATE_FORMAT(r.created_date, '%Y-%m-%d') as created_date
from used_goods_board b, used_goods_reply r
where b.board_id = r.board_id and DATE_FORMAT(b.created_date,'%Y-%m') = '2022-10'
order by r.created_date asc, b.title asc
