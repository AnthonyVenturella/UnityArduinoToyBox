using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class ToggleLights : MonoBehaviour{

    static SerialPort connection;

    //TODO: make these fillable by the user
    string portName = "COM4";
    int baudRate = 9600;

    void Start() {
        connection = new SerialPort();

        connection.PortName = portName;
        connection.BaudRate = baudRate;

        //TODO: replace above with func calls that prompt user
        //connection.PortName = SetPortName(connection.PortName);
        //connection.BaudRate = SetBaudRate(connection.BaudRate);

        //connection.ReadTimeout = 5;
        connection.WriteTimeout = 5;

        if (connection.IsOpen) { connection.Close(); Debug.Log("PORT WAS OPEN!"); } else { connection.Open(); }

    }

    public void ToggleRed() {
        //Serial write 1
        connection.WriteLine("1");
    }

    public void ToggleGreen() {
        //Serial write 2
        connection.WriteLine("2");
    }

    public void ToggleYellow() {
        //Serial write 3
        connection.WriteLine("3");
    }

    public void ToggleBlue() {
        //Serial write 4
        connection.WriteLine("4");
    }

    private void OnApplicationQuit() {
        //closes the port on app exit
        if (connection.IsOpen) { connection.Close(); }
    }

    private void OnDisable() {
        //closes the port on script disable. i.e. when a scene change happens if this isnt made persistent
        if (connection.IsOpen) { connection.Close(); }
    }
}
