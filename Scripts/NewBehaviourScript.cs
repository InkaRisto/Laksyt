using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NewBehaviourScript : MonoBehaviour
{
    [SerializeField] private float n_LaunchForce = 150;

    private Rigidbody2D rigidbody;
    private Rigidbody2D otherRigidbody;
    private bool launch;
    private Vector2 LaunchDirection;

    private float timeBoosted;

    // Start is called before the first frame update
    void Awake()
    {
      rigidbody = GetComponent<Rigidbody2D>();
        }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButton(0)) {
            timeBoosted += Time.deltaTime;
        }
        if (Input.GetMouseButtonUp(0))
        {
            launch = true;
            var ScreenToWorldPoint = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            var direction = (transform.position - ScreenToWorldPoint).normalized;
            LaunchDirection = direction;
        }

    }

    private void FixedUpdate()
    {
        if (launch)
        {
            Debug.Log("Launch ball");
            var LaunchForce = LaunchDirection * timeBoosted * n_LaunchForce;
            rigidbody.AddForce(LaunchForce, ForceMode2D.Impulse);
            timeBoosted = 0;
            launch = false;

        }

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Goal"))
        {
            Debug.Log("Reached Goal");
            SceneManager.LoadScene(gameObject.scene.buildIndex);
        }    
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Enemy"))
        {
            Debug.Log("Death achieved");
            SceneManager.LoadScene(gameObject.scene.buildIndex);
        }
    }

}



