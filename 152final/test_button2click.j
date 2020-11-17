.source test
.class test_button2click
.super java/lang/Object
.implements java/awt/event/ActionListener

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Ltest_button2click;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public actionPerformed(Ljava/awt/event/ActionEvent;)V
.var 0 is this Ltest_button2click;
.var 1 is e Ljava/awt/event/ActionEvent;
;
; 032 nums=nums+2
;
	getstatic	test/nums I
	iconst_2
	iadd
	putstatic	test/nums I
;
; 033 lab2.setText("Clicked: "+nums)
;
	getstatic	test/lab2 Ljavax/swing/JLabel;
	ldc	"Clicked: "
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	test/nums I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	return
.limit locals 3
.limit stack 7
.end method
