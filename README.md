# Button-Driven-Non-Blocking-Blink-Wokwi
## EN
I made a non-blocking blink using millis() without delay(). I wanted to practice before starting to RTOS. Since delay locks up the CPU and multiple tasks cannot be performed simultaneously, I prepared it using millis().

A pushbutton on D2 is defined as INPUT_PULLUP and short press is toggle the on-board led, long press is change blink rate (cycles between 150ms and 1000ms).

Features:
----------> millis() based cooperative timing

----------> button press/release detection

----------> one-shot long-press handling

----------> serial logs

----------> Short press toggles D13 + prints a log

----------> Hold the button more than 3 second (long press) changes the blink period (150-350-550-..-1000)




##TR
Delay kullanmadan millis ile bir blink led çalışması yaptım. Delay'in CPU'yu kilitlediğinin farkındayım ve bu esnada birden fazla görev gerçekleştirilemiyor. Bu sebeple RTOS öğrenmeye başlamadan önce delay yerine millis kullandım.

Buton D2'ye bağlı durumda ve INPUT_PULLUP olarak tanımladım. RTOS'a başlamadan önce yapıyı tam olarak anlayabilmem için iskelet olarak tasarladım ve zamanla bu sistemi geliştirerek RTOS öğrenmeyi hedefliyorum.

Özellikler:
----------> millis tabanlı bir zamanlama sistemi kullandım

----------> butonda basılı tutma ve bırakma algılama işlevini ekledim

----------> Seri loglar ile kısa süre basma/uzun süre basma ve led yandı - blink hızı değişti tarzında geri dönüş haberi veriliyor

----------> Butona 3 saniyeden fazla basıldığında herhangi bir etki olmuyor, uzun basma tek sefer tetikleniyor.
