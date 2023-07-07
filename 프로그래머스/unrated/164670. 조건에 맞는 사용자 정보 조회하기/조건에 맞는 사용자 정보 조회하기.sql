-- 코드를 입력하세요
SELECT u.user_id, u.nickname,concat(u.city," ",u.street_address1," ",u.street_address2) as "전체주소" , concat(substr(u.tlno,1,3),"-",substr(u.tlno,4,4),"-",substr(u.tlno,8)) as "전화번호"
from used_goods_board b, used_goods_user u
where b.writer_id = u.user_id
group by b.writer_id
having count(b.board_id) >= 3
order by u.user_id desc
