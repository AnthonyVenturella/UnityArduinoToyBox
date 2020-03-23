//TODO:
//  - Polish the code
//  - Prompt user for input of PortName
//  - Prompt User for input of BaudRate

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class SendVertSpeed : MonoBehaviour{

    [SerializeField] GameObject flyingBlock;
    public Rigidbody rb;

    static SerialPort connection;

    //TODO: make these fillable by the user
    string portName = "COM3";
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
    
    void Update(){

        rb = flyingBlock.GetComponent<Rigidbody>();

        if (Input.GetButtonDown("Jump")) {
            rb.velocity = new Vector3(0, 10, 0) + rb.velocity;

        }

        Debug.Log("current Velocity: " + rb.velocity.y);

        //program sends to serial current blocks yPos, arduino code compares to previous and displays the change
        //float altitude = flyingBlock.transform.position.y;
        //Debug.Log("current Altitude: " + altitude);

        connection.WriteLine(rb.velocity.y.ToString());
    }

    private void OnApplicationQuit() {
        //closes the port on app exit
        if (connection.IsOpen) { connection.Close(); }
    }

    private void OnDisable() {
        //closes the port on script disable. i.e. when a scene change happens if this isnt made persistent
        if (connection.IsOpen) { connection.Close(); }
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
