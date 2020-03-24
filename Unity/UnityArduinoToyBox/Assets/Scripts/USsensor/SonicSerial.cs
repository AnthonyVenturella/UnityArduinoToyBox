//TODO:
//  - Polish the code
//  - Prompt user for input of PortName
//  - Prompt User for input of BaudRate

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class SonicSerial : MonoBehaviour{

    [SerializeField] GameObject moveableBox;

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

        connection.ReadTimeout = 5;
        //connection.WriteTimeout = 5; //for use in code that writes

        if (connection.IsOpen) { connection.Close(); Debug.Log("PORT WAS OPEN!"); } else { connection.Open(); }

    }

    // Update is called once per frame
    void Update()
    {
        //only runs if there is something in serial
        if (connection.BytesToRead > 0) {
            //Reads the serial one line at a time, so if printing to serial make sure you do seperate info on a new line
            //  If this doesnt work for you try any of the other functions: "Read" "ReadByte" ReadChar" "ReadExisting" "ReadTo"
            //  https://docs.microsoft.com/en-us/dotnet/api/system.io.ports.serialport.read?view=netframework-4.8

            string serialInput = connection.ReadLine();
            int inputValue;

            //checks if valid input then randomly sets the color
            if (int.TryParse(serialInput, out inputValue)) {
                //Debug.Log("Recieved Distance value: " + inputValue + "cm");

                float zPos = mapValue(inputValue, 0, 200, 0, 100);

                //Debug.Log("Recieved Unity Distance value: " + zPos);

                moveableBox.transform.position = new Vector3(0f, 0f, zPos);

            }
        }
    }

    private void OnApplicationQuit() {
        //closes the port on app exit
        if (connection.IsOpen) { connection.Close(); }
    }

    private void OnDisable() {
        //closes the port on script disable. i.e. when a scene change happens if this isnt made persistent
        if (connection.IsOpen) { connection.Close(); }
    }

    public static float mapValue(float valueToMap, float fromMin, float fromMax, float toMin, float toMax) {
        float returnValue = (valueToMap - fromMin) / (fromMax - fromMin) * (toMax - toMin) + toMin;

        if(returnValue > toMax) {
            return toMax;
        } else {
            return returnValue;
        }
    }

    //TODO
    public static string SetPortName(string defaultPortName) {
        return "";
    }

    //TODO
    public static int setBaudRate(int defaultBaudRate) {
        return 0;
    }
}
