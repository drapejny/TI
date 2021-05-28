package by.bsuir.drapejny;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;

import java.io.*;

public class Controller {
    @FXML
    private TextField pTextField;
    @FXML
    private TextField qTextField;
    @FXML
    private Label rText;
    @FXML
    private Button signatureButton;
    @FXML
    private Button checkSignatureButton;
    @FXML
    private TextField dTextField;
    @FXML
    private Label eText;
    @FXML
    private Label SText;
    @FXML
    private Label hashText;
    @FXML
    private TextField fileTextField;
    @FXML
    private Label mText;
    @FXML
    private Label _mText;
    @FXML
    private Label _sText;

    long p;
    long q;
    long r;
    long u;
    long e;
    long d;
    long hash;
    long s;
    File fileToSign;

    public void initialize() {
    System.out.println(46340 * 46342);

        signatureButton.setOnAction(event -> {
            if (setParameters()) {
                byte[] bytes = readFileToSign();
                if (bytes == null) {
                    showError("Не выбран файл");
                    return;
                }
                hash = hashFunction(bytes, r);
                hashText.setText(Long.toString(hash));
                s = fastExp(hash, d, r);
                SText.setText(Long.toString(s));
                writeSignedFile(s);
            }
        });

        checkSignatureButton.setOnAction(event -> {
            if (setParameters()) {
                String message = readSignedFile();
                if (message == null) {
                    showError("Не выбран файл");
                    return;
                }
                int sigIndex = message.lastIndexOf('|');
                if (sigIndex == -1) {
                    showError("Подпись не обнаружена");
                    return;
                }
                int signature = 0;
                try {
                    signature = Integer.parseInt(message.substring(sigIndex + 1));
                } catch (NumberFormatException e) {
                    showError("Некорректная подпись");
                    return;
                }

                long m = fastExp(signature, e, r);

                message = message.substring(0, sigIndex);

                byte[] bytes = message.getBytes();

                long messageHash = hashFunction(bytes, r);

                if(m == messageHash)
                    showSucces("Подпись принадлежит отправителю");
                else showError("Подпись не принадлежит отправителю");

                mText.setText(Long.toString(m));
                _mText.setText(Long.toString(messageHash));
                _sText.setText(Long.toString(signature));
            }
        });
    }

    public String readSignedFile() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Text files", "*.txt"));
        File file = fileChooser.showOpenDialog(checkSignatureButton.getScene().getWindow());
        String result = "";
        //если не выбрали файл, то метод возвращает null
        if (file != null) {
            try (FileReader fileReader = new FileReader(file)) {
                int c;
                while ((c = fileReader.read()) != -1) {
                    result += (char) c;
                }
            } catch (FileNotFoundException fileNotFoundException) {
                fileNotFoundException.printStackTrace();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        } else return null;
        return result;
    }

    public void writeSignedFile(long s) {
        try (FileWriter fileWriter = new FileWriter(fileToSign, true)) {
            String signature = Long.toString(s);
            fileWriter.write("|" + signature);
        } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }

    public long hashFunction(byte[] bytes, long r) {
        long h = 100;
        h = h % r;
        for (int i = 0; i < bytes.length; i++) {
            long mi = Byte.toUnsignedLong(bytes[i]);
            System.out.println("hash " + h + " mi " + mi );
            h = fastExp(h + mi, 2, r);
        }
        System.out.println(h + "------------------");
        return h;
    }

    public byte[] readFileToSign() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Text files", "*.txt"));
        File file = fileChooser.showOpenDialog(signatureButton.getScene().getWindow());
        byte[] result = null;
        //если не выбрали файл, то метод возвращает null
        if (file != null) {
            try (FileInputStream fis = new FileInputStream(file)) {
                result = new byte[fis.available()];
                fis.read(result);
                fileToSign = file;
            } catch (FileNotFoundException fileNotFoundException) {
                fileNotFoundException.printStackTrace();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }
        return result;
    }

    public boolean setParameters() {
        //проверка p
        try {
            p = Long.parseLong(pTextField.getText());
            if (p < 2 || p > 2147483646 || !isSimple(p))
                throw new Exception();
        } catch (Exception exception) {
            showError("Неверный ввод p");
            return false;
        }
        //проверка q
        try {
            q = Long.parseLong(qTextField.getText());
            if (q < 2 || q == p  || q > 2147483647 || !isSimple(q))
                throw new Exception();
        } catch (Exception exception) {
            showError("Неверный ввод q");
            return false;
        }
        r = p * q;
        u = (p - 1) * (q - 1);
        //проверка e
        try {
            d = Long.parseLong(dTextField.getText());
            if (d < 2 || d >= u || NOD(u, d) != 1) {
                throw new Exception();
            }
        } catch (Exception exception) {
            showError("Неверный ввод d");
            return false;
        }
        e = euclid(u, d);
        eText.setText(Long.toString(e));
        rText.setText(Long.toString(r));

        return true;
    }

    public long euclid(long a, long b) {
        long d0 = a;
        long d1 = b;
        long x0 = 1;
        long x1 = 0;
        long y0 = 0;
        long y1 = 1;
        while (d1 > 1) {
            long q = d0 / d1;
            long d2 = d0 % d1;
            long x2 = x0 - q * x1;
            long y2 = y0 - q * y1;
            d0 = d1;
            d1 = d2;
            x0 = x1;
            x1 = x2;
            y0 = y1;
            y1 = y2;
        }
        if (y1 < 0)
            y1 += a;
        return y1;
    }


    public long fastExp(long value, long stepen, long mod) {
        value = value % mod;
        long result = 1;
        while (stepen != 0) {
            while ((stepen % 2) == 0) {
                stepen = stepen / 2;
                value = (value * value) % mod;
            }
            stepen -= 1;
            result = (result * value) % mod;
        }
        return result;
    }

    public long NOD(long a, long b) {
        while (a > 0 && b > 0)
            if (a > b) a %= b;
            else b %= a;
        return a + b;
    }

    public boolean isSimple(long num) {
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public void showError(String textOfError) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setHeaderText(textOfError);
        alert.showAndWait();
    }

    public void showSucces(String textOfSucces){
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText(textOfSucces);
        alert.showAndWait();
    }
}
