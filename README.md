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

----------> External LED and potentiometer added.

----------> Communication with the serial monitor and command line reading have been added. The commands listed below are now available. [v1.1]

| Command | Usage                      | Description                                          |
| ------- | -------------------------- | ---------------------------------------------------- |
| `HELP`  | `HELP`                     | Lists commands or shows details.                     |
| `GET`   | `GET PWM\|POT\|MODE\|RATE` | Reads current state.                                 |
| `SET`   | `SET PWM <0-255>`          | Sets PWM and switches to **MAN** mode.               |
| `MODE`  | `MODE AUTO\|MAN [PWM]`     | Switches control mode; optional PWM for MAN.         |
| `RATE`  | `RATE <50-2000>`           | Sets blink period (ms).                              |
| `LONG`  | `LONG <ms>`                | Sets long-press threshold (recommended 500–8000 ms). |



## TR

Delay kullanmadan millis ile bir blink led çalışması yaptım. Delay'in CPU'yu kilitlediğinin farkındayım ve bu esnada birden fazla görev gerçekleştirilemiyor. Bu sebeple RTOS öğrenmeye başlamadan önce delay yerine millis kullandım.

Buton D2'ye bağlı durumda ve INPUT_PULLUP olarak tanımladım. RTOS'a başlamadan önce yapıyı tam olarak anlayabilmem için iskelet olarak tasarladım ve zamanla bu sistemi geliştirerek RTOS öğrenmeyi hedefliyorum.

Özellikler:

----------> millis tabanlı bir zamanlama sistemi kullandım

----------> butonda basılı tutma ve bırakma algılama işlevini ekledim

----------> Seri loglar ile kısa süre basma/uzun süre basma ve led yandı - blink hızı değişti tarzında geri dönüş haberi veriliyor

----------> Butona 3 saniyeden fazla basıldığında herhangi bir etki olmuyor, uzun basma tek sefer tetikleniyor.

----------> Harici led ve potansiyometre ile ledin aydınlığını ayarlama eklendi.

----------> Seri monitör ile haberleşme ve komut satırı okuma eklendi. Aşağıda yer alan komutlar artık kullanılabiliyor. (v1.1)

| Komut  | Kullanım                   | Açıklama                                                                    |
| ------ | -------------------------- | ----------------------------------------------------------------------------|
| `HELP` | `HELP`                     | Komutları gösterir.                                                         |
| `GET`  | `GET PWM\|POT\|MODE\|RATE` | Mevcut değerleri gösterir.                                                  |
| `SET`  | `SET PWM <0-255>`          | PWM değerini ayarlar ve **MAN** moda geçer.                                 |
| `MODE` | `MODE AUTO\|MAN [PWM]`     | PWM kontrol modunu değiştirir. AUTO modda potansiyometre ile kontrol edilir.|
| `RATE` | `RATE <50-2000>`           | Blink periyodunu ayarlar.                                                   |
| `LONG` | `LONG <ms>`                | Uzun basma minimum süreyi ayarlar.                                          |
