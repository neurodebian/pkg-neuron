Description:  very dirty -- simply commented out what was supposed to come from iv3text* 

--- a/src/ivoc/mlinedit.cpp
+++ b/src/ivoc/mlinedit.cpp
@@ -2,7 +2,8 @@
 #if HAVE_IV // to end of file
 
 #include <stdio.h>
-#include <InterViews/iv3text.h>
+//#include <InterViews/iv3text.h>
+#include <IV-2_6/InterViews/textbuffer.h>
 #include <InterViews/layout.h>
 #include <InterViews/background.h>
 #include <InterViews/event.h>
@@ -12,7 +13,7 @@
 #include "oc2iv.h"
 #include "apwindow.h"
 
-class OcText : public Text {
+class OcText { //: public Text {
 public:
 	OcText(unsigned rows = 24, unsigned cols = 80, TextBuffer* buf = nil);
 	virtual ~OcText();
@@ -46,17 +47,23 @@ static double map(void* v) {
 
 static double readonly(void* v) {
 	OcMLineEditor* e = (OcMLineEditor*)v;
+    // disabling added interfaces on top of ivtools
+    return 0;
+    /*
 	if (ifarg(1)) {
 		e->txt_->readOnly(int(chkarg(1, 0, 1)));
 	}
 	return double(e->txt_->readOnly());
+    */
 }
 
 static char** v_text(void* v) {
 	OcMLineEditor* e = (OcMLineEditor*)v;
-	TextBuffer* tb = e->txt_->editBuffer();
+    // disabling added interfaces on top of ivtools
+	TextBuffer* tb = 0; // welcome SEGFAULT ;) // e->txt_->editBuffer();
 	if (ifarg(1)) {
-		e->txt_->reset();
+        // disabling added interfaces on top of ivtools
+		// e->txt_->reset();
 		const char* s = gargstr(1);
 		tb->Insert(0, s, strlen(s));
 	}
@@ -89,7 +96,7 @@ static void* cons(Object*) {
 		col = unsigned(chkarg(3, 1, 1000));
 	}
 	OcMLineEditor* e = new OcMLineEditor(row, col, buf);
-	e->ref();
+	// e->ref();
 	return (void*)e;
 }
 
@@ -98,7 +105,7 @@ static void destruct(void* v) {
 	if (e->has_window()) {
 		e->window()->dismiss();
 	}
-	e->unref();
+	// e->unref();
 }
 
 void TextEditor_reg() {
@@ -107,35 +114,35 @@ void TextEditor_reg() {
 
 OcMLineEditor::OcMLineEditor(unsigned row, unsigned col, char* buf) {
 	txt_ = new OcText(row, col, new TextBuffer(buf,strlen(buf),1000));
-	txt_->ref();
-	body(
-		new Background(
-			txt_,
-			WidgetKit::instance()->background()
-		)
-	);
+	// txt_->ref();
+	// body(
+	// 	new Background(
+	// 		txt_,
+	// 		WidgetKit::instance()->background()
+	// 	)
+	// );
 }
 OcMLineEditor::~OcMLineEditor() {
-	txt_->unref();
+	// txt_->unref();
 }
 
-OcText::OcText(unsigned rows, unsigned cols, TextBuffer* buf) :
-	Text(rows, cols, buf)
+OcText::OcText(unsigned rows, unsigned cols, TextBuffer* buf)// :
+//	Text(rows, cols, buf)
 {
 }
 
 OcText::~OcText() {}
 
 void OcText::keystroke(const Event& e){
-  if (readOnly_) {
-    return;
-  }
+    //if (readOnly_) {
+    //  return;
+    //}
   char buffer[8]; // needs to be dynamically adjusted
   int count = e.mapkey(buffer, 8);
   if (count <= 0) {
     return;
   }
-	Text::keystroke(e);
+  //Text::keystroke(e);
 }
 
 #endif
