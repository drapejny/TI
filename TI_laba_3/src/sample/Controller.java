package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;

import java.io.*;
import java.util.HashSet;

public class Controller {

    @FXML
    private ListView<Integer> primRootsListView;
    @FXML
    private TextField pTextField;
    @FXML
    private TextField xTextField;
    @FXML
    private TextField kTextField;
    @FXML
    private Button generateButton;
    @FXML
    private Text gText;
    @FXML
    private Button encryptButton;
    @FXML
    private Button chooseButton;
    @FXML
    private TextField filePathTextField;
    @FXML
    private Text encText;
    @FXML
    private Text decText;
    @FXML
    private Button decryptButton;

    File file = new File("files\\test.txt");
    String extencion;
    public ObservableList<Integer> observableList = FXCollections.observableArrayList();

    int p;
    int x;
    int k;
    int g;
    int y;
    int a;
    int b;

    public void initialize() {
        encText.setText("Enc: ");
        decText.setText("Dec: ");
        primRootsListView.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                gText.setText("g = " + observableList.get(primRootsListView.getSelectionModel().getSelectedIndex()));
            }
        });

        encryptButton.setVisible(false);

        generateButton.setOnAction(actionEvent -> {
            encryptButton.setVisible(false);
            try {
                p = Integer.parseInt(pTextField.getText());
                if (p < 1)
                    throw new Exception();
            } catch (Exception e) {
                showAlert("Некорректный ввод p");
                observableList.clear();
                return;
            }
            if (!isSimple(p)) {
                showAlert("p не простое число");
                observableList.clear();
                return;
            }
            observableList.clear();
            for (int i = 1; i < p; i++) {
                if (isPrimRoot(p, i))
                    observableList.add(i);
            }
            primRootsListView.setItems(observableList);
            encryptButton.setVisible(true);
        });

        encryptButton.setOnAction(actionEvent -> {
            if (primRootsListView.getSelectionModel().getSelectedIndex() == -1) {
                showAlert("Не выбрано значение g");
                return;
            } else {
                try {
                    k = Integer.parseInt(kTextField.getText());
                    if (k <= 1 || k >= p - 1)
                        throw new Exception();
                    if (NOD(k, p - 1) != 1)
                        throw new Exception();
                } catch (Exception e) {
                    showAlert("Некорректный ввод k");
                    return;
                }
                try {
                    x = Integer.parseInt(xTextField.getText());
                    if (x <= 1 || x >= p - 1)
                        throw new Exception();
                } catch (Exception e) {
                    showAlert("Некорректный ввод x");
                    return;
                }
                g = observableList.get(primRootsListView.getSelectionModel().getSelectedIndex());
                gText.setText("g = " + g);
            }

            byte[] buffer;
            try (FileInputStream fis = new FileInputStream(file);
                 FileOutputStream encFout = new FileOutputStream("files\\enc");) {
                buffer = new byte[fis.available()];
                if (buffer.length == 0) {
                    showAlert("Выбранный файл пуст");
                    return;
                }
                fis.read(buffer, 0, buffer.length);

                y = fastExp(g, x, p);
                a = fastExp(g, k, p);
                for (int i = 0; i < buffer.length; i++) {
                    int m = Byte.toUnsignedInt(buffer[i]);
                    b = (fastExp(y, k, p) * (m % p)) % p;
                    encFout.write((byte) (a >> 8));
                    encFout.write((byte) a);
                    encFout.write((byte) (b >> 8));
                    encFout.write((byte) b);
                    System.out.println(m + " [" + a + ", " + b + "]");
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

        });

        decryptButton.setOnAction(actionEvent -> {
            byte[] buffer;
            try (FileInputStream fis = new FileInputStream("files\\enc");
                 FileOutputStream decFout = new FileOutputStream("files\\dec" + extencion)) {
                buffer = new byte[fis.available()];
                fis.read(buffer,0,buffer.length);
                for(int i = 0; i < buffer.length; i += 4){
                    a = Byte.toUnsignedInt(buffer[i]);
                    a = (a << 8) + Byte.toUnsignedInt(buffer[i + 1]);
                    b = Byte.toUnsignedInt(buffer[i + 2]);
                    b = (b << 8) + Byte.toUnsignedInt(buffer[i + 3]);
                    int m = b * fastExp(fastExp(a, x, p), p - 2, p) % p;
                    decFout.write((byte) m);
                    System.out.println(m + " [" + a + ", " + b + "]");
                }
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
    }


    public boolean isPrimRoot(int p, int g) {

        HashSet<Integer> primFactors = getPrimFactors(p - 1);
        for (Integer factor : primFactors) {
            if (fastExp(g, (p - 1) / factor, p) == 1) {
                return false;
            }
        }
        return true;
    }

    public HashSet<Integer> getPrimFactors(int value) {
        HashSet<Integer> result = new HashSet<>();
        for (int i = 2; i <= Math.sqrt(value); i++) {
            while (value % i == 0) {
                result.add(i);
                value /= i;
            }
        }
        if (value != 1) {
            result.add(value);
        }
        return result;
    }

    public int fastExp(int value, int stepen, int mod) {
        value = value % mod;
        int result = 1;
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


    public boolean isSimple(int num) {
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int NOD(int a, int b) {
        while (a > 0 && b > 0)
            if (a > b) a %= b;
            else b %= a;
        return a + b;
    }

    public void showAlert(String textOfError) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Ошибка ввода");
        alert.setHeaderText(textOfError);
        alert.showAndWait();
    }
}
