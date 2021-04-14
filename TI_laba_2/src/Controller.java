import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import javafx.scene.text.TextFlow;
import javafx.stage.FileChooser;

import java.io.*;
import java.util.regex.Matcher;

public class Controller {

    @FXML
    private TextField startSequenceTextField;
    @FXML
    private TextField filePathTextField;
    @FXML
    private Button chooseButton;
    @FXML
    private Text binCounterText;
    @FXML
    private Button encryptButton;
    @FXML
    private Text keyText;
    @FXML
    private Text currentFileText;
    @FXML
    private Text encryptedFileText;

    String startSequence = "";
    File file;
    String extencion = "";
    LFSR lfsr;

    public void initialize() {
        startSequenceTextField.setText("111111111111111111111111111111");

        encryptButton.setOnAction(actionEvent -> {
            keyText.setText("");
            currentFileText.setText("");
            encryptedFileText.setText("");

            //Проверяем введенную строку на 0 и 1
            startSequence = "";
            boolean noOneFlag = true;
            for (int i = 0; i < startSequenceTextField.getText().length(); i++) {
                if (startSequenceTextField.getText().charAt(i) == '0' ||
                        startSequenceTextField.getText().charAt(i) == '1') {
                    startSequence += startSequenceTextField.getText().charAt(i);
                    if(startSequenceTextField.getText().charAt(i) == '1')
                        noOneFlag = false;
                }
            }
            if (startSequence.length() != 30) {
                showAlert("Длина начальной последовательности не равна 30");
                return;
            }
            if(noOneFlag) {
                showAlert("Введено запрещенное состояние");
                return;
            }


            if (file == null) {
                showAlert("Не выбран файл");
                return;
            }


            lfsr = new LFSR(startSequence, 1, 15, 16, 30);

            byte[] buffer;

            try (FileInputStream fin = new FileInputStream(file)) {

                buffer = new byte[fin.available()];
                
                if(buffer.length == 0){
                    showAlert("Выбранный файл пуст");
                    return;
                }

                fin.read(buffer, 0, buffer.length);

                FileOutputStream encFout = new FileOutputStream("C:/Users/User/Desktop/LFSR/encryptedFile");
                FileOutputStream decFout = new FileOutputStream("C:/Users/User/Desktop/LFSR/decryptedFile" + extencion);

                String keyStr = "";
                String currentFileStr = "";
                String encryptedFileStr = "";

                boolean flag = buffer.length <= 20; //Флаг для вывода

                for (int i = 0; i < buffer.length; i++) {
                    byte currentByte = buffer[i];
                    byte keyByte = lfsr.getKeyByte();
                    byte encryptedByte = (byte) (keyByte ^ currentByte);
                    byte decryptedByte = (byte) (keyByte ^ encryptedByte);

                    encFout.write(encryptedByte);
                    decFout.write(decryptedByte);

                    //Вывод на экран
                    if (flag) { //если размер файла меньше 20 байт
                        keyStr += getBits(keyByte) + "  ";
                        currentFileStr += getBits(currentByte) + "  ";
                        encryptedFileStr += getBits(encryptedByte) + "  ";
                    } else if (i < 10 || i >= buffer.length - 10) { //иначе выводим первые и последние 5 байтов
                        keyStr += getBits(keyByte) + "  ";
                        currentFileStr += getBits(currentByte) + "  ";
                        encryptedFileStr += getBits(encryptedByte) + "  ";
                    } else if (i == 10) {
                        keyStr += " ... ";
                        currentFileStr += " ... ";
                        encryptedFileStr += " ... ";
                    }
                }

                keyText.setText(keyStr);
                currentFileText.setText(currentFileStr);
                encryptedFileText.setText(encryptedFileStr);

                System.out.println(keyStr);
                System.out.println(currentFileStr);
                System.out.println(encryptedFileStr);

                decFout.close();
                encFout.close();

            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        chooseButton.setOnAction(actionEvent -> {
            FileChooser fileChooser = new FileChooser();
            file = fileChooser.showOpenDialog(chooseButton.getScene().getWindow());
            filePathTextField.setText(file.getPath());
            //Выделяем расширение файла
            if (file.getName().lastIndexOf(".") != -1 && file.getName().lastIndexOf(".") != 0)
                extencion = file.getName().substring(file.getName().lastIndexOf("."));
            else extencion = "";
        });
        startSequenceTextField.textProperty().addListener((observable, oldValue, newValue) -> {
            int counter = 0;
            for (int i = 0; i < newValue.length(); i++) {
                if (newValue.charAt(i) == '1' || newValue.charAt(i) == '0') {
                    counter++;
                }
            }
            binCounterText.setText(Integer.toString(counter));
        });
    }

    public String getBits(byte b) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 8; i++)
            result.append((b & (1 << i)) == 0 ? "0" : "1");
        result.reverse();
        return result.toString();
    }

    public void showAlert(String textOfError) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Ошибка");
        alert.setHeaderText("Ошибка ввода");
        alert.setContentText(textOfError);
        alert.showAndWait();
    }
}
