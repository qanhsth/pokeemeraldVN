SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Làm sao ngươi tới được đây\n"
	.string "mà không cần tàu ngầm?\l"
	.string "Nhóc con này ghê quá!\p"
	.string "Nhưng… chuyện đó không liên quan\n"
	.string "tới chuyện ngươi tới đây phá.\p"
	.string "Và, ta muốn trả lại chuyện đã\n"
	.string "xảy ra ở VIỆN KHÍ TƯỢNG…\p"
	.string "Ta sẽ cho ngươi nếm chút mùi đau\n"
	.string "khổ! Chuẩn bị tinh thần đi!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ây da!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Ngươi mạnh quá.\p"
	.string "Đúng là thất vọng tràn trề khi\n"
	.string "ngươi không phải thành viên ĐỘI AQUA.\p"
	.string "Ngươi đã có thể tận hưởng thế giới\n"
	.string "tuyệt vời mà ÔNG TRÙM đã hứa với\l"
	.string "tụi ta…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Để giấc mơ thành hiện thực, tụi ta\n"
	.string "cần phải có sức mạnh của POKéMON.\p"
	.string "Nhưng mà nhóc con như ngươi lại sử\n"
	.string "dụng POKéMON để phá tụi ta kể cả\l"
	.string "là một chỗ như vầy!\p"
	.string "Cuộc sống không hoạt động\n"
	.string "như cách mà chúng ta muốn!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gừào!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Ngươi biết là tụi ta không\n"
	.string "dám hỏi động cơ của thủ lĩnh.\p"
	.string "Nhưng mà ngươi, một đứa nhóc vô danh,\n"
    .string "đòi thách thức ÔNG TRÙM của tụi ta.\p"
	.string "Không lẽ…\n"
	.string "Ngươi là thứ gì đó sao…$"

