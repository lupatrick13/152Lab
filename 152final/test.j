.class public test
.super java/lang/Object
.field private static _mainframe Ljavax/swing/JFrame;

.field private static _sysin Ljava/util/Scanner;
.field private static lab Ljavax/swing/JLabel;
.field private static nums I
.field private static pan Ljavax/swing/JPanel;

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

.var 0 is number2 I
;
; 009 number2=2;
;
	iconst_2
	istore_0

	iload_0
	ireturn

.limit locals 1
.limit stack 1
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
; 015 pan.add(lab,'hello'+nums)
;
	getstatic	test/pan Ljavax/swing/JPanel;
	getstatic	test/lab Ljavax/swing/JLabel;
	ldc	"hello"
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	test/nums I
	invokevirtual	java/lang/StringBuilder/append(Ljava/lang/String;)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;

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
