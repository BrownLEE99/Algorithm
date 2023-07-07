-- 코드를 입력하세요
SELECT concat("/home/grep/src/",b.board_id,"/",FILE_ID,FILE_NAME,FILE_EXT) as FILE_PATH
from used_goods_board b, used_goods_file f
where b.board_id = f.board_id and 
        b.views = ( select MAX(bb.views)
                    from used_goods_board bb)
order by f.file_id desc