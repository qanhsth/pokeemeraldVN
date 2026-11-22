SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Có giường nè…\n"
	.string "Nằm nghỉ xíu đi.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Tui hay đi phà tới TP.BIỂN lắm.\p"
	.string "Bạn thấy đó, tui\n"
	.string "khoái đi THI lắm.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Trận đấu quá mãn nguyện!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Tui rất là hứng thú để coi POKéMON\n"
	.string "mà tui sẽ gặp trong CUỘC THI tới.\l"
	.string "Nôn nóng quá đi!$"

SSTidalRooms_Text_MicahIntro:
	.string "Mấy bạn có mạnh không?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Mấy bạn, ừ thì, mạnh thiệt.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Bạn bè không cần thiết phải là người ta.\n"
	.string "Với tui, POKéMON mới là bạn thực sự!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Nhóc…\n"
	.string "Có gõ cửa không đó?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Thua thì chấp nhận chứ đừng\n"
	.string "hấp tấp hay hoảng loạn.$"

SSTidalRooms_Text_ThomasPostBattle:
    .string "Luôn giữ bình tĩnh trong mọi tình huống\n"
    .string "là nguyên tắc ứng xử của một QUÝ ÔNG.$"

SSTidalRooms_Text_JedIntro:
	.string "NHÂN: Tui hơi ngại, nhưng mà…\n"
	.string "Tụi tui sẽ phô diễn sức mạnh tình iu!$"

SSTidalRooms_Text_JedDefeat:
	.string "NHÂN: Thở dài…$"

SSTidalRooms_Text_JedPostBattle:
	.string "NHÂN: Lần đầu tiên sức mạnh tình iu\n"
	.string "của tụi tui không áp đảo được đối thủ!\l"
	.string "Bạn chắc phải là NHL tuyệt vời!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "NHÂN: Chỉ có 1 POKéMON thôi sao?\n"
	.string "Không thấy cô đơn hả?$"

SSTidalRooms_Text_LeaIntro:
	.string "HẠNH: Cảm giác hơi ngố, nhưng mà…\n"
	.string "Tụi tui sẽ phô diễn sức mạnh tình iu!$"

SSTidalRooms_Text_LeaDefeat:
	.string "HẠNH: Ụa, trời ơi!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "HẠNH: Không thể tin được!\n"
	.string "Sức mạnh tình iu bị đánh bại…\l"
	.string "Bạn chắc phải là NHL tuyệt vời!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "HẠNH: Tui muốn thách đấu…\n"
	.string "Mà bạn còn không có nổi 2 POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Aa, tới đúng lúc đó.\p"
	.string "Tui đang chán quá.\n"
	.string "Bạn phải giải trí cho tui.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Cũng được đó.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Chắc tui phải nhờ ba mua một\n"
    .string "chiếc du thuyền mới được.\l"
    .string "Một chiếc du thuyền cho tui với POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Ủa, bạn đúng là NHL dễ thương.\n"
	.string "Bạn có muốn một tách trà?\l"
	.string "Hay là một ván đấu?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Hiểu rồi.\n"
	.string "Bạn là kiểu người năng động.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Du ngoạn vòng quanh thế giới trên\n"
    .string "chiếc thuyền lộng lẫy, phải công nhận…\p"
    .string "Mà, tui cũng phải thừa nhận là khám phá\n"
    .string "HOENN bằng phà cũng có sức hút riêng.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Ừm… Chào! Tui… tui không phải kẻ xấu!\n"
	.string "Ừm… Cho bạn nè! Miễn phí!\p"
	.string "Thực… Thực ra là, tui không có CHỘP LẤY\n"
	.string "của ai đâu! Tui không có làm chuyện\l"
	.string "như vậy đâu! Thiệt mà! Cứ xài đi!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "CHỘP LẤY cướp đi hiệu ứng tốt\n"
	.string "của chiêu thức trước khi được\l"
	.string "sử dụng bởi đối thủ hoặc đồng minh.$"

