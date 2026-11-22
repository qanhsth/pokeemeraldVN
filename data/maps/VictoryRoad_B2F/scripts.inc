VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Tui huấn luyện chung với nhà tui,\n"
	.string "mỗi người tụi tui luôn!\l"
	.string "Tui sẽ không thua một ai!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Giỏi hơn nhà tui luôn?!\n"
	.string "Sao có thể?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Tui là người giỏi nhất trong nhà\n"
	.string "rồi. Tui có thua ai bao giờ đâu…\p"
	.string "Tui mất hết sự tự tin rồi…\n"
	.string "Chắc phải về thôi…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Nghe nói ở đây có đứa nhóc mạnh\n"
	.string "lắm. Phải em không?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Nhóc con này mạnh thiệt!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Những gì anh nghe được, là\n"
	.string "đứa nhóc đó tới từ TP.HOA CAM.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Chắc bạn phải mệt rồi.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Không mệt xíu nào luôn!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "CON ĐƯỜNG VINH QUANG và LIÊN ĐOÀN\n"
	.string "POKéMON rất dài và gian nan.\l"
	.string "Cẩn thận, không là xỉu đó!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Đừng có tưởng mình có nhiều\n"
	.string "HUY HIỆU là hay.\p"
	.string "Sẽ luôn luôn có người\n"
	.string "giỏi hơn bạn đó!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Bạn giỏi hơn tui rồi!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Ngắm lại HUY HIỆU đã lấy được, rồi\n"
	.string "nhớ lại NHL mà mình từng gặp đi.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Tới được đây rồi, nhưng mà sự căng\n"
	.string "thẳng làm tui đau bụng dữ dội…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Trờiiợiii…\n"
	.string "Đau…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Không thể không căng thẳng khi\n"
	.string "biết mình sắp tới LIÊN ĐOÀN POKéMON.\p"
	.string "Tui chỉ có thể giả bộ bình tĩnh thôi.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Những người cực giỏi trong số những\n"
	.string "người cực giỏi tụ họp trong hang này.\p"
	.string "Bạn thấy sao?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Không do dự hay gì luôn!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Bạn có gan đó! Tui rất thích!\n"
	.string "Cố lên!$"

