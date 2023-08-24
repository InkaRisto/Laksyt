using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Platform : MonoBehaviour
{
    private void OnTriggerExit2D(Collider2D collision)

    {
        if (collision.attachedRigidbody.CompareTag("Player"))
        {
            if ((transform.position.y) < collision.transform.position.y)
            {
                Debug.Log("Player went over platform");
                Camera.main.GetComponent<CameraController>().SetCameraHeight(transform.position.y);
            }
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}


