.source test
.class public test
.super java/lang/Object
.field private static _mainframe Ljavax/swing/JFrame;

.field private static _sysin Ljava/util/Scanner;
.field protected static box1 Ljavax/swing/JTextField;
.field protected static but Ljavax/swing/JButton;
.field protected static but2 Ljavax/swing/JButton;
.field protected static dpan Ljavax/swing/JPanel;
.field protected static lab Ljavax/swing/JLabel;
.field protected static lab2 Ljavax/swing/JLabel;
.field protected static lpan Ljavax/swing/JPanel;
.field protected static nums I
.field protected static opan Ljavax/swing/JPanel;
.field protected static rpan Ljavax/swing/JPanel;
.field protected static upan Ljavax/swing/JPanel;

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	test/_sysin Ljava/util/Scanner;

	new	javax/swing/JFrame
	dup
	ldc	"test"
	invokespecial	javax/swing/JFrame/<init>(Ljava/lang/String;)V
	dup
	putstatic	test/_mainframe Ljavax/swing/JFrame;
	getstatic	javax/swing/JFrame/EXIT_ON_CLOSE I
	invokevirtual	javax/swing/JFrame/setDefaultCloseOperation(I)V
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Ltest;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; FUNCTION number2
;
.method private static number2()I

.var 1 is number2 I
.var 0 is temp I
;
; 012 temp=2
;
	iconst_2
	istore_0
;
; 013 number2=temp;
;
	iload_0
	istore_1

	iload_1
	ireturn

.limit locals 2
.limit stack 1
.end method

;
; FUNCTION initialize
;
.method private static initialize(I)V

.var 0 is i I
.var 1 is testlabel Ljavax/swing/JLabel;
.var 2 is yo Ljavax/swing/JPanel;
;
; 019 yo.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	astore_2
;
; 020 testlabel.create("TESTIITIITI"+i)
;

	new	javax/swing/JLabel
	dup
	ldc	"TESTIITIITI"
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	iload_0
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokespecial	javax/swing/JLabel/<init>(Ljava/lang/String;)V
	astore_1
;
; 021 yo.add(testlabel,"North")
;

	aload_2
	aload_1
	ldc	"North"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 022 yo.finish("South")
;

	getstatic	test/_mainframe Ljavax/swing/JFrame;
	aload_2
	ldc	"South"
	invokevirtual	javax/swing/JFrame/add(Ljava/awt/Component;Ljava/lang/Object;)V

	return

.limit locals 3
.limit stack 16
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

;
; 037 nums=0
;
	iconst_0
	putstatic	test/nums I
;
; 038 initialize(100)
;
	bipush	100
	invokestatic	test/initialize(I)V
;
; 039 Lpan.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	putstatic	test/lpan Ljavax/swing/JPanel;
;
; 040 Rpan.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	putstatic	test/rpan Ljavax/swing/JPanel;
;
; 041 Upan.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	putstatic	test/upan Ljavax/swing/JPanel;
;
; 042 Dpan.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	putstatic	test/dpan Ljavax/swing/JPanel;
;
; 043 Opan.create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	putstatic	test/opan Ljavax/swing/JPanel;
;
; 044 box1.create()
;

	new	javax/swing/JTextField
	dup
	invokespecial	javax/swing/JTextField/<init>()V
	putstatic	test/box1 Ljavax/swing/JTextField;
;
; 045 lab.create("Number of clicks : 0")
;

	new	javax/swing/JLabel
	dup
	ldc	"Number of clicks : 0"
	invokespecial	javax/swing/JLabel/<init>(Ljava/lang/String;)V
	putstatic	test/lab Ljavax/swing/JLabel;
;
; 046 but.create("Click me!")
;

	new	javax/swing/JButton
	dup
	ldc	"Click me!"
	invokespecial	javax/swing/JButton/<init>(Ljava/lang/String;)V
	putstatic	test/but Ljavax/swing/JButton;
;
; 047 but.addAction(button1click.)
;
	getstatic	test/but Ljavax/swing/JButton;
	new	test_button1click
	dup
	invokespecial	test_button1click/<init>()V
	invokevirtual	javax/swing/JButton/addActionListener(Ljava/awt/event/ActionListener;)V
;
; 048 for(nums=5to10){nums=nums+1;}
;
	iconst_5
	putstatic	test/nums I
L002:
	getstatic	test/nums I
	bipush	10
	if_icmpgt	L003
	iconst_0
	goto	L004
L003:
	iconst_1
L004:
	ifne	L001
;
; 050 nums=nums+1;
;
	getstatic	test/nums I
	iconst_1
	iadd
	putstatic	test/nums I
	getstatic	test/nums I
	iconst_1
	iadd
	putstatic	test/nums I
	goto	L002
L001:
;
; 053 if(nums>9){lab2.create("I am the right side"+nums);}
;
	getstatic	test/nums I
	bipush	9
	if_icmpgt	L006
	iconst_0
	goto	L007
L006:
	iconst_1
L007:
	ifeq	L005
;
; 054 lab2.create("I am the right side"+nums)
;

	new	javax/swing/JLabel
	dup
	ldc	"I am the right side"
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	test/nums I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokespecial	javax/swing/JLabel/<init>(Ljava/lang/String;)V
	putstatic	test/lab2 Ljavax/swing/JLabel;
L005:
;
; 056 but2.create("DO NOT CLICK")
;

	new	javax/swing/JButton
	dup
	ldc	"DO NOT CLICK"
	invokespecial	javax/swing/JButton/<init>(Ljava/lang/String;)V
	putstatic	test/but2 Ljavax/swing/JButton;
;
; 057 but2.addAction(button2click.)
;
	getstatic	test/but2 Ljavax/swing/JButton;
	new	test_button2click
	dup
	invokespecial	test_button2click/<init>()V
	invokevirtual	javax/swing/JButton/addActionListener(Ljava/awt/event/ActionListener;)V
;
; 058 Lpan.add(lab,"North")
;

	getstatic	test/lpan Ljavax/swing/JPanel;
	getstatic	test/lab Ljavax/swing/JLabel;
	ldc	"North"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 059 Lpan.add(but,"South")
;

	getstatic	test/lpan Ljavax/swing/JPanel;
	getstatic	test/but Ljavax/swing/JButton;
	ldc	"South"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 060 Rpan.add(lab2,"North")
;

	getstatic	test/rpan Ljavax/swing/JPanel;
	getstatic	test/lab2 Ljavax/swing/JLabel;
	ldc	"North"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 061 Rpan.add(but2,"South")
;

	getstatic	test/rpan Ljavax/swing/JPanel;
	getstatic	test/but2 Ljavax/swing/JButton;
	ldc	"South"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 062 Upan.add(Lpan,"West")
;

	getstatic	test/upan Ljavax/swing/JPanel;
	getstatic	test/lpan Ljavax/swing/JPanel;
	ldc	"West"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 063 Upan.add(Rpan,"East")
;

	getstatic	test/upan Ljavax/swing/JPanel;
	getstatic	test/rpan Ljavax/swing/JPanel;
	ldc	"East"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 064 Dpan.add(box1,"Center")
;

	getstatic	test/dpan Ljavax/swing/JPanel;
	getstatic	test/box1 Ljavax/swing/JTextField;
	ldc	"Center"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 065 Opan.add(Dpan,"South")
;

	getstatic	test/opan Ljavax/swing/JPanel;
	getstatic	test/dpan Ljavax/swing/JPanel;
	ldc	"South"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 066 Opan.add(Upan,"North")
;

	getstatic	test/opan Ljavax/swing/JPanel;
	getstatic	test/upan Ljavax/swing/JPanel;
	ldc	"North"
	invokevirtual	javax/swing/JPanel/add(Ljava/awt/Component;Ljava/lang/Object;)V
;
; 067 Opan.finish("North")
;

	getstatic	test/_mainframe Ljavax/swing/JFrame;
	getstatic	test/opan Ljavax/swing/JPanel;
	ldc	"North"
	invokevirtual	javax/swing/JFrame/add(Ljava/awt/Component;Ljava/lang/Object;)V

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	getstatic	test/_mainframe Ljavax/swing/JFrame;
	dup
	invokevirtual	javax/swing/JFrame/pack()V
	ldc	1
	invokevirtual	javax/swing/JFrame/setVisible(Z)V

	return

.limit locals 6
.limit stack 7
.end method
