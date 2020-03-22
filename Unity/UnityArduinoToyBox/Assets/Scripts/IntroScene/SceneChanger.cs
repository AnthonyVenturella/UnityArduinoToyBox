using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneChanger : MonoBehaviour {
    
    public void ButtonScene() {
        SceneManager.LoadScene("Button");
    }

    public void AccelerometerScene() {
        SceneManager.LoadScene("Accelerometer_GY-61");
    }

    public void JoystickScene() {
        SceneManager.LoadScene("Joystick");
    }

    public void LEDlightsScene() {
        SceneManager.LoadScene("LEDlights");
    }

    public void USsensorScene() {
        SceneManager.LoadScene("USsensor");
    }

    public void VertSpeedScene() {
        SceneManager.LoadScene("VertSpeed");
    }

    public void ExitGame() {
        Application.Quit();
    }
}
