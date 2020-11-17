.source test
.class test_button1click
.super java/lang/Object
.implements java/awt/event/ActionListener

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Ltest_button1click;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public actionPerformed(Ljava/awt/event/ActionEvent;)V
.var 0 is this Ltest_button1click;
.var 1 is e Ljava/awt/event/ActionEvent;
;
; 027 nums=nums+1
;
	getstatic	test/nums I
	iconst_1
	iadd
	putstatic	test/nums I
;
; 028 lab.setText("Clicked: "+nums)
;
	getstatic	test/lab Ljavax/swing/JLabel;
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
