SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Bạn có biết POKéMON SEEDOT không?\n"
	.string "Rất là hiếm thấy ở LƯU NIẾT.\p"
	.string "Mà tui thích con SEEDOT bự này quá.\n"
	.string "Càng bự càng tốt.\p"
	.string "Mà thằng em tui nói, là con\n"
	.string "LOTAD bự hơn.\p"
	.string "Nghe ngố ghê.\n"
	.string "SEEDOT phải bự hơn chứ!\p"
	.string "Hử? Bạn có đem con SEEDOT hả?\n"
	.string "Ê ch-ch-cho tui coi thử đi!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} inches!\n"
	.string "Trời đất ơi, bự quá!\p"
	.string "Còn bự hơn con LOTAD mà\n"
	.string "thằng em tui thấy nữa!\p"
	.string "Cảm ơn vì đã cho tui coi.\n"
	.string "Đây là một chút lòng thành của tui!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hửm?\n"
	.string "TÚI bạn đầy nhóc rồi.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} inches, đúng không?\p"
	.string "Hừm… tui từng thấy con SEEDOT\n"
	.string "bự hơn luôn.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Ờm, cũng được á chứ…\n"
	.string "Nhưng mà đâu phải SEEDOT đâu!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Bạn không có SEEDOT cỡ lớn hả?\n"
	.string "Chán ghê…\p"
	.string "Nếu bạn có SEEDOT cỡ lớn,\n"
	.string "hãy đem lại cho tui coi.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "SEEDOT bự nhất trong lịch sử!\n"
	.string "{STR_VAR_2} bự hơn {STR_VAR_3} inch!\p"
	.string "Con SEEDOT bự hơn con LOTAD\n"
	.string "mà tui luôn muốn có!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Bạn có biết POKéMON LOTAD không?\n"
	.string "Hiếm gặp ở LƯU NIẾT lắm.\p"
	.string "Tui thích, ý là rất thích, LOTAD cỡ bự!\p"
	.string "Anh tui nói là con SEEDOT\n"
	.string "mới bự hơn.\p"
	.string "Nhưng mà không phải đâu! Ai cũng biết\n"
	.string "là con LOTAD bự hơn nhiều.\p"
	.string "Hửm? Bạn có một con LOTAD hả?\n"
	.string "Ê ch-ch-cho tui thử đi!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} inches!\n"
	.string "Trời đất ơi, bự quá!\p"
	.string "Còn bự hơn con SEEDOT mà\n"
	.string "anh tui thấy nữa!\p"
	.string "Cảm ơn vì đã cho tui coi.\n"
	.string "Đây là một chút lòng thành của tui!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hửm?\n"
	.string "TÚI bạn đầy nhóc rồi.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} inches, đúng không?\p"
	.string "Hừm… tui từng thấy con LOTAD\n"
	.string "bự hơn luôn.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Trời, cũng ra gì á chớ!\n"
	.string "Nhưng mà không phải LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Bạn không có LOTAD bự hả?\n"
	.string "Thất vọng quá…\p"
	.string "Nếu bạn có LOTAD bự,\n"
	.string "hãy đem tới cho tui coi nha!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "LOTAD bự nhất trong lịch sử!\n"
    .string "{STR_VAR_2} bự hơn {STR_VAR_3} inch!\p"
    .string "Con LOTAD bự hơn SEEDOT\n"
    .string "mà tui luôn muốn có!$"

