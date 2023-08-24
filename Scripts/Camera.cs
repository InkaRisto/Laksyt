using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    [SerializeField] private float n_moveSpeed = 3f;
    [SerializeField] private float n_cameraOffset = 2.5f;
    [SerializeField] private float n_smoothTime = 1.0f;

    private Vector3 targetPosition;
    private Vector3 currentVelocity;

    private void Start()
    {
        targetPosition = transform.position;
    }
    public void SetCameraHeight(float y)
    {
        Debug.Log(y);
        targetPosition = new Vector3(
            transform.position.x,
            y * n_cameraOffset,
            transform.position.z);
    }
    public void LateUpdate()
    {
        transform.position = Vector3.SmoothDamp(transform.position, targetPosition, ref currentVelocity, n_smoothTime);
            //Vector3.MoveTowards(transform.position, targetPosition, Time.deltaTime * n_moveSpeed); <<< Old
    }
}

