FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Có gì đó đang xảy ra,\n"
	.string "cảm giác khó chịu ghê!\p"
	.string "Ta thấy có mấy người đang lảng vảng\n"
	.string "trước nhà TS.TINH làm gì đó mờ ám…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Từ hồi xưa, người tab iết tới\n"
	.string "vùng này là bởi thiên thạch.\p"
	.string "Người ta nói THÁC SAO BĂNG bị khoét 1 lỗ\n"
    .string "tại thiên thạch rớt xuống từ lâu rồi.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Coi nè! Coi nè!\n"
	.string "Đây là bé AZURILL dễ thương của tui!\p"
	.string "Vừa trơn, vừa mềm, mà còn êm nữa!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rừ ri rứ.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Con có thách đấu HOẢ LY,\n"
	.string "CHỦ GYM THỊ TRẤN NÚI LỬA chưa?\p"
	.string "Ông nội của con bé nổi tiếng lắm.\n"
	.string "Ổng là một trong các ĐẠI TỨ\l"
	.string "LIÊN ĐOÀN POKéMON.\p"
	.string "Không có gì bất ngờ khi thấy\n"
	.string "HOẢ LY trở thành NHL tài năng\l"
	.string "bằng thực lực của mình.$"

FallarborTown_Text_BattleTentSign:
	.string "HỘI THI ĐẤU NÔNG TRẠI NHỎ\n"
	.string "“Tập hợp Đội Hình Mạnh Nhất!”$"

FallarborTown_Text_TownSign:
	.string "NÔNG TRẠI NHỎ\n"
	.string "“Nông trại với những khu vườn nhỏ.”$"

FallarborTown_Text_MoveTutorSign:
	.string "NHÀ của THẦY DẠY CHIÊU\n"
	.string "“Dạy chiêu mới cho POKéMON.”$"

