RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Cái biểu cảm đó…\n"
	.string "Cái phong thái đó…\l"
	.string "Ngay cả POKéMON cũng được nuôi dưỡng kỹ…\p"
	.string "Con chắc phải là NHL tài giỏi rồi!\p"
	.string "Mà khoan, đừng có nói gì hết á.\n"
	.string "Chỉ cần nhìn con là chú biết rồi.\p"
	.string "Chắc chắn là con sẽ biết cách\n"
	.string "xài MÁY HỌC CHIÊU ẨN này rồi.\p"
	.string "Không cần phải ngần ngại đâu.\n"
	.string "Cầm lấy nó đi!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cái MÁY HỌC CHIÊU ẨN, hay nói\n"
	.string "tắt là HM, có chiêu CẮT.\p"
	.string "POKéMON có thể xài chiêu HM\n"
	.string "ở ngoài trận đấu.\p"
	.string "Bất kỳ POKéMON nào học được chiêu CẮT\n"
	.string "đều có thể chặt cây non xuống, nhưng\l"
	.string "NHL phải có HUY HIỆU ĐÁ mới được.\p"
	.string "Và, không giống như TM,\n"
	.string "HM có thể xài được nhiều lần.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Lúc mà người ta mở rộng TP.KIM THÁN,\n"
	.string "ba tui đã giúp đỡ rất nhiều.\p"
	.string "Ổng cho POKéMON xài CẮT để\n"
	.string "dọn bớt cây cho trống đường.$"

