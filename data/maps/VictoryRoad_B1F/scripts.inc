VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Nghĩ tới chuyện mình sắp tới\n"
	.string "LIÊN ĐOÀN POKéMON…\p"
	.string "Làm tui hồi hộp quá trời…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Không làm gì được luôn á…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "LIÊN ĐOÀN POKéMON lại trở nên\n"
	.string "xa vời rồi… Hụt hẫng quá…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Để thắng được LIÊN ĐOÀN POKéMON,\n"
	.string "bạn cần phải tin tưởng\l"
	.string "vô POKéMON của mình.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Mối quan hệ của mấy bạn\n"
	.string "dựa trên lòng tin sâu sắc.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Ở cùng nhau mọi lúc, lòng tin\n"
	.string "giữa POKéMON và NHL sẽ lớn lên.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Đây đâu phải đích. Nó chỉ là cái\n"
	.string "đường tới LIÊN ĐOÀN POKéMON mà thôi.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Vầy mới đúng nè!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Bạn đang làm tốt, chắc luôn!\n"
	.string "POKéMON của bạn rất nôn nóng!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "POKéMON của tui đúng là biết\n"
    .string "cách làm người ta phải kinh ngạc!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Đó giờ chưa gặp được ai như bạn.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Kể cả ngoài ván đấu, tui cảm nhận được\n"
	.string "sức mạnh khủng khiếp thoát ra từ bạn\l"
	.string "với POKéMON của bạn.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Được rồi, không cần gồng mình đâu!\n"
	.string "Thoải mái, thư giãn đi!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Trờiii!\n"
	.string "Quá hay luôn!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Đúng, đây là CON ĐƯỜNG VINH QUANG.\p"
	.string "Nhưng mà nó không có khác mấy con\n"
	.string "đường mà bạn từng đi qua lắm đâu.\p"
	.string "Thôi cứ thử trải nghiệm\n"
	.string "phần đường còn lại là biết mà!$"

