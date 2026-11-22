SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Tui sẽ cho bạn thấy kỹ nghệ mà\n"
	.string "tui đã học được từ Ông CHUẨN!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Thưa Ông CHUẨN, tôi xin tạ lỗi…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Coi chừng làm nứt sàn\n"
	.string "đó nha.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Bạn tới được đây rồi, nhưng mà\n"
	.string "bạn sẽ không gặp được Ông CHUẨN đâu.\p"
	.string "Trừ khi hạ được tui!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Mạnh thiệt!\n"
	.string "Tui bị cái ngơ của bạn làm phân tâm!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Chắc bạn sẽ có thể chịu được\n"
	.string "đòn nhất sát của Ông CHUẨN.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Khung cảnh Ông CHUẨN chỉ đạo\n"
    .string "cho một ván đấu…\p"
    .string "Khoảnh khắc đẹp đẽ đó đã thôi thúc\n"
    .string "tui trở thành một NHL.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Vẻ đẹp khi chiến đấu của bạn\n"
	.string "còn đẹp hơn tui nữa…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "Sự duyên dáng mà bạn mang đến\n"
    .string "trong ván đấu thật là mỹ miều.\p"
    .string "Ôi… Cảm thấy thật may mắn khi\n"
    .string "tìm được POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Tui sẽ dạy cho bạn biết\n"
	.string "chiến trường khắc nghiệt cỡ nào.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Trời.\n"
	.string "Cũng mạnh á.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Tui sẽ cho bạn biết cái này.\p"
	.string "Nếu muốn tới chỗ Ông CHUẨN, bạn phải\n"
	.string "đi lên mỗi ô gạch một lần.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "NHÀ THI ĐẤU có POKéMON cấp độ\n"
	.string "cao nhất vùng HOENN…\p"
	.string "Đó chính là NHÀ THI ĐẤU LƯU NIẾT.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Bạn ở tầm cao khác rồi!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Tui nghĩ tập luyện ở nhiều nơi\n"
	.string "sẽ làm mình mạnh hơn là an nhàn \l"
	.string "ở một cái NHÀ THI ĐẤU mạnh như vầy.\l"
	.string "Nhưng mà trên hết, ở đây cũng vui mà.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "Tui luyện POKéMON chung với\n"
	.string "Ông CHUẨN.\p"
	.string "Đừng có tưởng tui dễ ăn.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "Dễ ăn thiệt…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Tui nghĩ bạn có tiềm năng á.\n"
	.string "Sao không ở lại, luyện với tụi tui?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Trượt băng uyển chuyển mà không\n"
    .string "trúng ai…\p"
    .string "Nếu một NHL làm được chuyện đó, thì\n"
    .string "người đó thật là thanh tao và lộng lẫy!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Ụa, xin lỗi?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "Mà thực ra cũng đúng thôi, cái chuyện\n"
	.string "mạnh hay yếu đối với một NHL như bạn,\l"
	.string "không liên quan tới chuyện già hay trẻ.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Khi ở cùng POKéMON, thời gian trôi qua\n"
	.string "trước khi bạn kịp nói, “Ủaaa!”$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Ủaaa!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "Ước gì có thể quên đi chuyện vô vọng\n"
    .string "trước khi tui kịp nói “Ủaaa!”$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Tui có thể thách đấu bằng POKéMON\n"
	.string "cực hiếm nếu bạn thích.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Ủa, mà! Bạn có nhìn kỹ\n"
	.string "POKéMON của tui chưa?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Tui tới đây bởi vì Ông CHUẨN\n"
	.string "khen tui có con POKéMON dễ thương.\p"
	.string "Mà trời, nếu mà được gặp ổng\n"
	.string "lúc còn trẻ thì…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Hí hí…\n"
	.string "Vẻ mặt u ám của bạn nhìn quyến rũ ghê.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Ôi trời.\n"
	.string "Nương tay hơi quá rồi.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Bạn không chạm được một ngón lên\n"
	.string "Ông CHUẨN đâu, chắc luôn. Hí hí…$"

