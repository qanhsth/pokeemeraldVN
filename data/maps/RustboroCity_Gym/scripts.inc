RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Ô, hé lô!\p"
	.string "Nói nghe nè bạn!\n"
	.string "Bạn có muốn làm NHÀ VÔ ĐỊCH không?\p"
	.string "Tui không có phải là NHL, nhưng\n"
	.string "mà tui sẽ cho bạn gợi ý để thắng.\p"
	.string "Quyết định rồi nha! Tụi mình đều\n"
	.string "hướng tới CHỨC VÔ ĐỊCH POKéMON!\p"
	.string "Là NHL phải đi thu thập\n"
	.string "HUY HIỆU đúng chưa?\p"
	.string "Nhưng CHỦ GYM không phải dạng vừa đâu!\p"
	.string "Bởi vậy nên phải có tui,\n"
	.string "đứng đây để gợi ý cho bạn nè!\p"
	.string "CHỦ GYM LỚP TRƯỞNG, là\n"
	.string "người chơi POKéMON hệ ĐÁ.\p"
	.string "Hệ Đá rất trâu, nhưng\n"
	.string "không thể chịu được\l"
	.string "chiêu hệ NƯỚC với hệ CỎ.\p"
	.string "Thắng được CHỦ GYM rồi quay\n"
	.string "lại cảm ơn tui sau cũng được.\p"
	.string "Rồi, đánh hết mình đi!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Trời! Chiến thắng mỹ mãn ha!\n"
	.string "Vậy là phải cảm ơn tui đó!\p"
	.string "Rồi giờ vô coi lại\n"
	.string "THẺ HUẤN LUYỆN đi.\p"
	.string "HUY HIỆU ĐÁ mà bạn đã\n"
	.string "nhận chắc chắn phải có trên đó.\p"
	.string "Nói cách khác…\p"
	.string "Bạn đã bước thêm một\n"
	.string "bước tới con đường VÔ ĐỊCH!\p"
	.string "Đã chưa!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Đừng có nghĩ NHL trong đây yếu!\n"
	.string "Tui sẽ cho bạn thấy sức mạnh của tui!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Bạn mạnh quá dạ…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Bạn không có biết sức mạnh\n"
	.string "của hệ ĐÁ kinh khủng cỡ nào đâu!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Nếu mà thua tui, thì bạn không\n"
	.string "có cửa với LỚP TRƯỞNG đâu!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Trời! Cũng có tiềm năng đó chứ!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "LỚP TRƯỞNG mạnh hơn\n"
	.string "tui gấp mấy lần đó.\p"
	.string "Bạn nên chuẩn bị tinh thần đi!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Có lẽ ta đang ở giữa thị trấn,\n"
	.string "nhưng vậy thì đã sao chứ?\p"
	.string "Mấy con POKéMON hệ ĐÁ\n"
	.string "cũng cần có chỗ để quậy!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Trời ơi!\n"
	.string "Người này đúng là một đối thủ xứng tầm!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Chắc chỉ còn nhờ vào LỚP TRƯỞNG thôi.\p"
	.string "Ở độ tuổi trẻ vậy nhưng mà cách\n"
	.string "chọn POKéMON hệ ĐÁ rất là khôn khéo.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Chào, tui là LỚP TRƯỞNG,\n"
	.string "CHỦ GYM TP.KIM THÁN đây.\p"
	.string "Tui trở thành CHỦ GYM là để\n"
	.string "áp dụng những gì đã học ở TRƯỜNG\l"
	.string "HUẤN LUYỆN POKéMON vô trận đấu.\p"
	.string "Bạn có thể phô diễn cho tui cách\n"
	.string "mà bạn thách đấu POKéMON không?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Vậy à…\n"
	.string "Tui thua rồi…\p"
	.string "Chắc tui cần phải\n"
	.string "học thêm nữa…\p"
	.string "Tui hiểu rồi.\p"
	.string "Luật của LIÊN ĐOÀN POKéMON\n"
	.string "nói là những ai đánh bại được\l"
	.string "CHỦ GYM, thì hãy đưa họ cái này.\p"
	.string "Xin hãy nhận lấy HUY HIỆU ĐÁ\n"
	.string "chính thức từ LIÊN ĐOÀN POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "LỚP TRƯỞNG trao HUY HIỆU ĐÁ\n"
	.string "cho {PLAYER}.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "HUY HIỆU ĐÁ sẽ làm tăng\n"
	.string "SÁT THƯƠNG cho POKéMON của bạn.\p"
	.string "Ngoài ra, nó còn cho phép POKéMON của bạn\n"
	.string "thi triển chiêu HM CẮT ngoài trận đấu.\p"
	.string "Xin hãy nhận lấy cái này nữa.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "MÁY HỌC CHIÊU, TM39,\n"
	.string "có chứa QUĂNG ĐÁ.\p"
	.string "Không chỉ gây ST bằng cách quăng\n"
	.string "đá thôi đâu, mà nó còn giảm TỐC nữa.\p"
	.string "Nếu bạn xài TM, nó sẽ dạy chiêu\n"
	.string "thức cho POKéMON ngay lập tức.\p"
	.string "Hãy nhớ, TM chỉ xài được 1 lần thôi,\n"
	.string "nên là suy nghĩ kỹ trước khi xài.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Giờ bạn đã mạnh rồi, bạn cũng\n"
	.string "thách đấu CHỦ GYM khác đi.\p"
	.string "Khi thách đấu nhiều người,\n"
	.string "bạn sẽ học được nhiều điều đó.$"

RustboroCity_Gym_Text_GymStatue:
	.string "NHÀ THI ĐẤU TP.KIM THÁN$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU TP.KIM THÁN\p"
	.string "LỚP TRƯỞNG CÔNG NHẬN NHL:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bíp!\p"
	.string "LỚP TRƯỞNG: Alo, {PLAYER} phải không?\n"
	.string "Tui là LỚP TRƯỞNG ở TP.KIM THÁN nè.\p"
	.string "Tui nghe ĐÔNG nói là bạn đang\n"
	.string "trên đà thăng tiến thứ hạng của\l"
	.string "các NHL với tốc độ kinh ngạc.\p"
	.string "Tui chắc chắn sẽ\n"
	.string "đánh bại được bạn mà thôi.\p"
	.string "Tui hứa sẽ cải tạo lại NHÀ THI ĐẤU để\n"
	.string "tụi mình có thể đấu với nhau lần nữa.\p"
	.string "Hy vọng bạn cũng mong\n"
	.string "chờ khoảnh khắc đó như tui!\p"
	.string "… … … … … …\n"
	.string "… … … … … Cạch!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Đã lưu số CHỦ GYM LỚP TRƯỞNG\n"
	.string "vô BẢN ĐỒ.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "LỚP TRƯỞNG: Tui rất vui được gặp lại bạn.\n"
	.string "Tui là LỚP TRƯỞNG, CHỦ GYM.\p"
	.string "Cả hai đứa mình đều đã trưởng\n"
	.string "thành kể từ lần cuối gặp nhau rồi ha.\p"
	.string "Tui cũng muốn thấy tụi mình đã mạnh\n"
	.string "lên cỡ nào rồi. Thách đấu thôi!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Gừư…\n"
	.string "Thua nữa rồi…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "LỚP TRƯỞNG: Vậy là tui vẫn còn nhiều\n"
	.string "thứ phải học về thách đấu POKéMON rồi.\p"
	.string "Nhận ra điều đó làm tui\n"
	.string "càng yêu thích thách đấu hơn!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "LỚP TRƯỞNG: Tui rất vui được gặp lại bạn.\n"
	.string "Tui là LỚP TRƯỞNG, CHỦ GYM.\p"
	.string "Cả hai đứa mình đều đã trưởng\n"
	.string "thành kể từ lần cuối gặp nhau rồi ha.\p"
	.string "Tui cũng muốn thấy tụi mình đã mạnh\n"
	.string "lên cỡ nào rồi…\p"
	.string "Ủa mà…\n"
	.string "Sao đem có 1 con POKéMON vậy?\p"
	.string "Xin hãy đem ít nhất 2 con\n"
	.string "POKéMON trở lên.$"
